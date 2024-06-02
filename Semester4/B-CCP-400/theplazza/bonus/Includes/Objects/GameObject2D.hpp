/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** GameObject2D
*/

#ifndef GAMEOBJECT2D_HPP_
    #define GAMEOBJECT2D_HPP_
    #include "GameObject.hpp"

namespace plazza
{
    class GameObject2D : public GameObject {
        public:
            GameObject2D(const std::string &textureName, const Vector2 position);

            void setTexture(const std::string &textureName) override;

            void setPosition(const Vector2 &position);
            const Vector2 getPosition() const;

        protected:
            Texture2D _texture;
            Vector2 _position;
    };
}

#endif /* !GAMEOBJECT_HPP_ */
