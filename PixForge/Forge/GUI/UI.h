#pragma once
#include "Tools/Tools.h"

#include "imgui.h"

// [FEATURE] Refactor the UI classes to be better

namespace PF{
  class UI{
    protected:
      static inline uint8_t count = 0;
      enum Type{
        LOG = 1,
        TEXT_EDITOR = 2,
        FILE_EXPLORER = 3
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
      const std::string windowID = std::to_string(UI::count++);
    public:
      Type getType() override { return Type::TEXT_EDITOR; };
      bool render() override;
  };

  class FileExplorerUI : public UI{
    private:
      const std::string windowID = std::to_string(UI::count++);
      Folder *folder;
    public:
      FileExplorerUI(Folder *folder);
      Type getType() override { return Type::FILE_EXPLORER; };
      bool render() override;
  };
}