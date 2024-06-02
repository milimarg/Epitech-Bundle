/*
** EPITECH PROJECT, 2024
** Global-Game-Jam---2024---Make-Me-Laugh
** File description:
** GameObject
*/

#include "GameObject.hpp"

namespace plazza
{
    GameObject::GameObject()
    :_timeBank(0.0f), _isHidden(false), _isTextured(false)
    {
    }

    void GameObject::setHidden(const bool hidden)
    {
        _isHidden = hidden;
    }
}
