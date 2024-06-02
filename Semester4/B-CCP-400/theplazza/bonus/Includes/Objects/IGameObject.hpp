/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** IGameObject
*/

#ifndef IGAMEOBJECT_HPP_
    #define IGAMEOBJECT_HPP_
    #include <iostream>
    #include <map>
    #include "RaylibWrapper.hpp"

namespace plazza
{
    class IGameObject {
        public:
            virtual ~IGameObject() = default;

            virtual void event() = 0;
            virtual void render() = 0;
            virtual void update(const float deltaTime) = 0;

            virtual void setTexture(const std::string &textureName) = 0;
            virtual void setHidden(const bool hidden) = 0;
    };
}


#endif /* !IGAMEOBJECT_HPP_ */
