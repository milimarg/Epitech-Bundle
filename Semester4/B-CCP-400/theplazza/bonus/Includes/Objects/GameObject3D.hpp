/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** GameObject3D
*/

#ifndef GAMEOBJECT3D_HPP_
    #define GAMEOBJECT3D_HPP_
    #include "GameObject.hpp"

namespace plazza
{
    class GameObject3D : public GameObject {
        public:
            GameObject3D(std::string &textureName, const Vector3 position);

            void setTexture(const std::string &textureName) override;

            void setPosition(const Vector3 &position);
            const Vector3 getPosition() const;

        protected:
            TextureCubemap _texture;
            Vector3 _position;
    };
}

#endif /* !GAMEOBJECT_HPP_ */
