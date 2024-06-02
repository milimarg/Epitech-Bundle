/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** GameObject3D
*/

#include "GameObject3D.hpp"

namespace plazza
{
    GameObject3D::GameObject3D(std::string &textureName, const Vector3 position)
    : GameObject(), _position(position)
    {
        if (textureName != "") {
            _isTextured = true;
            _texture = RaylibWrapper::getInstance().loadTexture3D(textureName);
        }
    }

    void GameObject3D::setTexture(const std::string &textureName)
    {
        _texture = LoadTexture(textureName.c_str());
    }

    void GameObject3D::setPosition(const Vector3 &position)
    {
        _position = position;
    }

    const Vector3 GameObject3D::getPosition() const
    {
        return _position;
    }
}
