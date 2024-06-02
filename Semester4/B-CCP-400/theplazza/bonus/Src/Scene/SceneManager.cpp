/*
** EPITECH PROJECT, 2024
** survivor
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "RaylibWrapper.hpp"
#include <iostream>

namespace plazza
{
    SceneManager &SceneManager::getInstance()
    {
        static SceneManager instance;
        return instance;
    }

    SceneManager::SceneManager()
        : _transitionAlpha(0), _transitionSpeed(0.001f)
    {
    }

    void SceneManager::pushScene(std::unique_ptr<IScene> scene)
    {
        capturePrecedingSceneScreenshot();

        _stackActions.push_back(stackActions::Push);
        _tmpSceneStack.push_back(std::move(scene));
        _transitionAlpha = 0;
    }

    void SceneManager::setScene(std::unique_ptr<IScene> scene)
    {
        capturePrecedingSceneScreenshot();

        if (!_sceneStack.empty())
            _sceneStack.pop();
        _sceneStack.push(std::move(scene));
        _transitionAlpha = 0;
    }

    void SceneManager::popScene()
    {
        capturePrecedingSceneScreenshot();

        if (!_sceneStack.empty())
            _stackActions.push_back(stackActions::Pop);
        _transitionAlpha = 255;
    }

    void SceneManager::updateSceneStack()
    {
        while (!_stackActions.empty()) {
            if (_stackActions.front() == stackActions::Pop) {
                _sceneStack.pop();
                _transitionAlpha = 0;
            } else {
                std::unique_ptr<IScene> newScene = std::move(_tmpSceneStack.front());
                _sceneStack.push(std::move(newScene));
                _tmpSceneStack.pop_front();
            }
            _stackActions.pop_front();
        }
    }

    void SceneManager::handleEvents()
    {
        if (!_sceneStack.empty())
            _sceneStack.top()->events();
        updateSceneStack();
    }

    void SceneManager::update()
    {
        float deltaTime = RaylibWrapper::getInstance().getDeltaTime();

        if (!_sceneStack.empty()) {
            _sceneStack.top()->update(deltaTime);
            updateTransition();
        }
    }

    void SceneManager::render()
    {
        if (!_sceneStack.empty())
            _sceneStack.top()->render();
    }

    void SceneManager::updateTransition()
    {
        if (_transitionAlpha < 255.0) {
            _transitionAlpha += _transitionSpeed * 255.0;
            if (_transitionAlpha > 255.0)
                _transitionAlpha = 255.0;
        } else if (_transitionAlpha > 0) {
            _transitionAlpha -= _transitionSpeed * 255.0;
            if (_transitionAlpha < 0.0)
                _transitionAlpha = 0.0;
        }
    }

    void SceneManager::drawTransition()
    {
        RaylibWrapper &raylib = RaylibWrapper::getInstance();

        if (_transitionAlpha > 0.0 && _precedingSceneTexture.id > 0) {
            Rectangle rec;
            rec.height = _precedingSceneTexture.height;
            rec.height = _precedingSceneTexture.width;
            rec.x = 0;
            rec.y = 0;
            raylib.drawTextureOnRectangle(
                rec,
                _precedingSceneTexture,
                Color{255, 255, 255, (unsigned char)(255.0 - _transitionAlpha)}
            );
        }
    }

    void SceneManager::setTransitionSpeed(float transitionSpeed)
    {
        _transitionSpeed = transitionSpeed;
    }

    void SceneManager::capturePrecedingSceneScreenshot()
    {
        if (!_sceneStack.empty()) {
            TakeScreenshot("currentScene.png");
            _precedingSceneTexture = LoadTexture("currentScene.png");
        }
    }
}
