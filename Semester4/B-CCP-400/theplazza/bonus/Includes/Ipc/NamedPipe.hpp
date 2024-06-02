/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** NamedPipe.hpp
*/

#ifndef B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_NAMEDPIPE_HPP
    #define B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_NAMEDPIPE_HPP
    #include <fstream>
    #include <iostream>
    #include "IIpc.hpp"

namespace plazza
{
    class NamedPipe : public IIpc {
        public:
            NamedPipe(const std::string &filepath);
            ~NamedPipe();

            bool openRead() override;
            bool openWrite() override;

            NamedPipe &operator<<(const std::string &string) override;
            NamedPipe &operator<<(const char *string) override;
            NamedPipe &operator>>(std::vector<std::string> &data) override;

        private:
            std::string _filepath;
            int _readFd;
            int _writeFd;
    };
}

#endif //B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_NAMEDPIPE_HPP
