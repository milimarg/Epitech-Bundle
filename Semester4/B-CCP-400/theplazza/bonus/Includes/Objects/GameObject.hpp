/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
    #define GAMEOBJECT_HPP_
    #include "IGameObject.hpp"

namespace plazza
{
    class GameObject : public IGameObject {
        public:
            GameObject();

            void setHidden(const bool hidden) override;
        protected:
            float _timeBank;
            bool _isHidden;
            bool _isTextured;
    };
}

#endif /* !GAMEOBJECT_HPP_ */
