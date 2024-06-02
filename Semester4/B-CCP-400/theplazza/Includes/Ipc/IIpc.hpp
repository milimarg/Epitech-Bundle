/*
** EPITECH PROJECT, 2024
** B-CCP-400-STG-4-1-theplazza-noe.tritsch
** File description:
** IIpc.hpp
*/

#ifndef B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_IPC_HPP
    #define B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_IPC_HPP
    #include <iostream>
    #include <vector>

namespace plazza
{
    class IIpc {
        public:
            virtual ~IIpc() = default;

            virtual bool openRead() = 0;
            virtual bool openWrite() = 0;

            virtual IIpc &operator<<(const std::string &string) = 0;
            virtual IIpc &operator<<(const char *string) = 0;
            virtual IIpc &operator>>(std::vector<std::string> &data) = 0;
    };
}

#endif //B_CCP_400_STG_4_1_THEPLAZZA_NOE_TRITSCH_IPC_HPP
