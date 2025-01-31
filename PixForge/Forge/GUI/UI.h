#pragma once
#include "Tools/Tools.h"

#include "imgui.h"

// [FEATURE] Refactor the UI classes to be better

namespace PF{
  class UI{
    protected:
      enum Type{
        NIL = 0,
        LOG = 1,
        FILE_EXPLORER = 2
      };
    public:
      static uint8_t generateUniqueID(Vector<UI*> *UIs);
    public:
      virtual uint8_t getType() = 0;
      virtual uint8_t getID() = 0;
      virtual bool render() = 0;
  };

  class LogUI : public UI{
    private:
      const uint8_t ID;
    public:
      LogUI(const uint8_t ID) : ID(ID) {};
      uint8_t getType() override { return Type::LOG; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };

  class TextEditorUI : public UI{
    private:
      std::string path;
      const uint8_t ID;
      char text[1024 * 1024] = "";
    private:
      void read();
    public:
      TextEditorUI(const uint8_t ID, std::string path);
      uint8_t getType() override { return Type::NIL; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };

  class FileExplorerUI : public UI{
    private:
      const uint8_t ID;
      Folder folder;
      Vector<UI*> *UIs;
    public:
      FileExplorerUI(const uint8_t ID, Vector<UI*> *UIs, Folder folder);
      uint8_t getType() override { return Type::FILE_EXPLORER; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };
}