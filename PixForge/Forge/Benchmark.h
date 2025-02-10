#pragma once
#include <chrono>
#include <string>
#include <vector>


namespace Benchmark{
class Benchmark{
  public:
  bool count_allocs = false;
  size_t allocs;
  size_t deallocs;
  public:
  std::vector<std::string> result;
  public:
  static Benchmark &get() {   
    static Benchmark benchmark;
    return benchmark; 
  };
}; // class Benchmark

class Timer{
  private:
  const std::string label;
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  public:
  Timer(const std::string &label = "Timer: ") : label(label), start(std::chrono::high_resolution_clock::now()) {};
  ~Timer(){
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if(duration.count() > 60000000)
      Benchmark::get().result.emplace_back(label + ": " + std::to_string(duration.count() / 60000000) + "." + std::to_string(duration.count() % 60000000) + " s");
    else if(duration.count() > 1000000)
      Benchmark::get().result.emplace_back(label + ": " + std::to_string(duration.count() / 1000000) + "." + std::to_string(duration.count() % 1000000) + " s");
    else if(duration.count() > 1000)
      Benchmark::get().result.emplace_back(label + ": " + std::to_string(duration.count() / 1000) + " ms");
    else if(duration.count() > 1)
      Benchmark::get().result.emplace_back(label + ": " + std::to_string(duration.count()) + " us");
  };
}; // class Timer

class Allocs{
  private:
    std::string label;
  public:
  Allocs(bool count = true, std::string label = "Allocs: ") : label(label)
    { Benchmark::get().count_allocs = count; Benchmark::get().allocs = 0; Benchmark::get().deallocs = 0; };
  ~Allocs() { 
    Benchmark::get().count_allocs = false; 
    Benchmark::get().result.emplace_back(label + ": " + std::to_string(Benchmark::get().allocs) + " allocs, " + std::to_string(Benchmark::get().deallocs) + " deallocs " + std::to_string(Benchmark::get().allocs - Benchmark::get().deallocs) + " leaks"); 
  };
  void start() { Benchmark::get().count_allocs = true; };
  void stop() { Benchmark::get().count_allocs = false; };
}; // class Allocs

}; // namespace Benchmark

void* operator new(size_t size) noexcept {
  if(Benchmark::Benchmark::get().count_allocs)
    Benchmark::Benchmark::get().allocs++;
  return malloc(size);
};

void operator delete(void *ptr) noexcept{
  if(Benchmark::Benchmark::get().count_allocs)
    Benchmark::Benchmark::get().deallocs++;
  free(ptr);
};

void operator delete(void *ptr, std::size_t size) noexcept {
  if(Benchmark::Benchmark::get().count_allocs)
      Benchmark::Benchmark::get().deallocs++;
  free(ptr);
}

void* operator new[](std::size_t count) noexcept {
  if(Benchmark::Benchmark::get().count_allocs)
    Benchmark::Benchmark::get().allocs++;
  return malloc(count);
}

void operator delete[](void *ptr) noexcept {
  if(Benchmark::Benchmark::get().count_allocs)
    Benchmark::Benchmark::get().deallocs++;
  free(ptr);
}

void operator delete[](void *ptr, std::size_t size) noexcept {
  if(Benchmark::Benchmark::get().count_allocs)
    Benchmark::Benchmark::get().deallocs++;
  free(ptr);
}