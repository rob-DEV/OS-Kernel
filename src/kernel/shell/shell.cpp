//
// Created by dev on 29/03/18.
//

#include <shell/shell.h>
#include <stdio.h>

namespace OS {

Shell* Shell::m_This = NULL;

ShellCommand::ShellCommand(const char *cmdText, void(*callback)()) {
    this->commandText = cmdText;
    this->callback = callback;
}

void ShellCommand::Execute() {
    callback();
}





Shell::Shell() {
    m_RegisteredCommandsLength = 0;
    m_CurrentLineBufferLength = 0;
}

Shell::~Shell() {

}

Shell* Shell::GetShell() {
    if(m_This != NULL)
        return m_This;

    m_This = new Shell();
    return m_This;
}

void Shell::RegisterCommand(const char *commandText, void(*callback)()) {

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
        m_RegisteredCommandsLength = 0;
    }


}

}