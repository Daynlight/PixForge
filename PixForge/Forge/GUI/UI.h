#pragma once
#include "Tools/Tools.h"

#include "imgui.h"

// [FEATURE] Refactor the UI classes to be better

namespace PF{
  class UI{
    protected:
      static inline uint8_t count = 0;
      enum Type{
        NIL = 0,
        LOG = 1,
        FILE_EXPLORER = 2
      };
    public:
      virtual Type getType() = 0;
      virtual bool render() = 0;
  };

  class LogUI : public UI{
    private:
      const std::string windowID = std::to_string(UI::count++);
    public:
      Type getType() override { return Type::LOG; };
      bool render() override;
  };

  class TextEditorUI : public UI{
    private:
      std::string path;
      const std::string windowID = std::to_string(UI::count++);
      char text[1024 * 1024] = "";
    private:
      void read();
    public:
      TextEditorUI(std::string path);
      Type getType() override { return Type::NIL; };
      bool render() override;
  };

  class FileExplorerUI : public UI{
    private:
      const std::string windowID = std::to_string(UI::count++);
      Folder folder;
      Vector<UI*> *UIs;
    public:
      FileExplorerUI(Vector<UI*> *UIs, Folder folder);
      Type getType() override { return Type::FILE_EXPLORER; };
      bool render() override;
  };
}