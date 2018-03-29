//
// Created by dev on 29/03/18.
//

#include <shell/shell.h>
#include <stdio.h>
#include <stdarg.h>

namespace OS {

Shell* Shell::m_This = NULL;
bool Shell::ShellEnabled = false;

ShellCommand::ShellCommand(const char *cmdText, void(*callback)()) {
    this->commandText = cmdText;
    this->callback = callback;
}

ShellCommand::~ShellCommand() {
}

void ShellCommand::Execute() {
    callback();
}





Shell::Shell() {
    ShellEnabled = true;
    m_RegisteredCommandsLength = 0;
    m_CurrentLineBufferLength = 0;

    printf("> Shell Initialized \n");
}

Shell::~Shell() {
    for(uint32_t i = 0; i < m_RegisteredCommandsLength; i++)
        delete m_RegisteredCommands[i];
}

Shell* Shell::GetShell() {
    if(m_This != NULL)
        return m_This;

    m_This = new Shell();
    return m_This;
}

void Shell::RegisterCommand(const char *commandText, const char *screen_message, void(*callback)()) {

    if(strlen(screen_message) > 0)
        printf("> %s\n", screen_message);

    m_RegisteredCommands[m_RegisteredCommandsLength] = new ShellCommand(commandText, callback);
    m_RegisteredCommandsLength++;
}
void Shell::CheckRegisteredCommands()
{

    for(int i = 0; i < m_RegisteredCommandsLength; i++)
    {
        if(strcmp(m_RegisteredCommands[i]->commandText, m_CurrentLineBuffer))
        {
            //execute the stored function for this command
            m_RegisteredCommands[i]->Execute();
        }
    }
}
void Shell::PutChar(char input) {

    if(!ShellEnabled)
        return;

    putch(input);

    // check the command if the character is \n
    if(input != '\n') {
        m_CurrentLineBuffer[m_CurrentLineBufferLength] = input;
        m_CurrentLineBufferLength++;
        return;
    }
    else {
        m_CurrentLineBuffer[m_CurrentLineBufferLength] = '\0';

        //check the commands
        CheckRegisteredCommands();

        //reset the buffer length for a new line
        m_CurrentLineBufferLength = 0;
    }


}

void Shell::Printf(const char * __restrict str, ...) {

    //
}


}