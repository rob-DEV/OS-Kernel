//
// Created by dev on 29/03/18.
//

#ifndef OS_SHELL_H
#define OS_SHELL_H

#include <common/types.h>

namespace OS {

    class ShellCommand {
    private:
        void (*callback)();

    public:
        const char * commandText;
    public:
        ShellCommand(const char * cmdText, void(*callback)());
        ~ShellCommand();

        void Execute();

    };

    class Shell {
    private:
        static Shell* m_This;
        ShellCommand* m_RegisteredCommands[80];
        uint32_t m_RegisteredCommandsLength;

        char* m_CurrentLineBuffer;
        uint32_t m_CurrentLineBufferLength;

        void CheckRegisteredCommands();

    public:
        Shell();
        ~Shell();
        static Shell* GetShell();
        static bool ShellEnabled;
        void RegisterCommand(const char *commandText, const char *screen_message, void(*callback)());
        void PutChar(char input);
        void Printf(const char * __restrict str, ...);
    };

}
#endif //OS_SHELL_H
