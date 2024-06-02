/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** Reception
*/

#include "Reception.hpp"
#include <iostream>
#include "Game.hpp"
#include "SceneManager.hpp"

namespace plazza
{
    Reception::Reception(
        double multiplier,
        int numCooksPerKitchen,
        int restockTime
    )
        : _timeBank(0.0f),
        _isStop(true),
        _writingOrder(false),
        _multiplier(multiplier),
        _numCooksPerKitchen(numCooksPerKitchen),
        _restockTime(restockTime)
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        AScene::addInput(
            Vector2{850.0f, 30.0f},
            Vector2{1050.0f, 80.0f},
            WHITE,
            {},
            [&](const std::string &input) {
                _input = input;
                processCommand(_input);
                for (auto &kitchen : _kitchens)
                    kitchen->handle();
                removeClosedKitchens();
                _writingOrder = false;
            },
            _input,
            100,
            false,
            [&](){
                _writingOrder = true;
            },
            [&](){
                _writingOrder = false;
            },
            "Input"
        );

        createCamera();
    }

    void Reception::createCamera()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

            _camera3D = r.createCamera(
            {10.0f, 10.0f, 10.0f},
            {0.0f, 2.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            60.0f,
            CAMERA_PERSPECTIVE
        );
        r.updateCamera(&_camera3D, CAMERA_FIRST_PERSON);
    }

    void Reception::initializeKitchens()
    {
        for (size_t i = 0; i < _kitchens.size(); ++i) {
            Vector3 kitchenPosition = {static_cast<float>(i) * 10.0f, 0.0f, 0.0f};
            _kitchens[i]->setPosition(kitchenPosition);
        }
    }

    Reception::~Reception()
    {
    }

    void Reception::events()
    {
        for (auto &object : _objects2D)
            object->event();
        for (auto &object : _objects3D)
            object->event();

        for (auto &kitchen : _kitchens)
            kitchen->handle();
        removeClosedKitchens();
    }

    void Reception::update(float deltaTime)
    {
        updateCamera(deltaTime);

        for (auto &object : _objects2D)
            object->update(deltaTime);
        for (auto &object : _objects3D)
            object->update(deltaTime);
        RaylibWrapper &r = RaylibWrapper::getInstance();
    }

    void Reception::render()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        r.beginDrawing();
        r.clearBackground(RAYWHITE);

        r.beginMode3D(_camera3D);
        drawKitchens();
        for (auto &object : _objects3D)
            object->render();
        r.endMode3D();

        for (auto &object : _objects2D)
            object->render();

        std::string cameraPositionText =
            "Camera Position: (" +
            std::to_string(_camera3D.position.x) + ", " +
            std::to_string(_camera3D.position.y) + ", " +
            std::to_string(_camera3D.position.z) + ")";

        r.drawText(cameraPositionText.c_str(), 10, 10, 20, BLACK);

        SceneManager::getInstance().drawTransition();

        r.endDrawing();
    }

    void Reception::drawKitchens()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        r.drawGrid(10000, 2.f);

        for (size_t i = 0; i < _kitchens.size(); ++i) {
            Vector3 kitchenPosition = _kitchens[i]->getPosition();

            r.drawCube(kitchenPosition, 5.0f, 3.0f, 2.0f + 2.0f * _numCooksPerKitchen, DARKGRAY);

            size_t ongoingOrders = _kitchens[i]->getOngoingOrders();
            size_t workingCooks = (ongoingOrders >= static_cast<size_t>(_numCooksPerKitchen)) ? _numCooksPerKitchen : ongoingOrders;
            size_t waitingPizzas = 0;
            if (ongoingOrders > _numCooksPerKitchen)
                waitingPizzas = ongoingOrders - _numCooksPerKitchen;

            for (int j = 0; j < _numCooksPerKitchen; ++j) {
                Vector3 cookPosition = {kitchenPosition.x, kitchenPosition.y + 2.0f, kitchenPosition.z + j * 2.0f - 1.0f};
                Color cookColor = (j < workingCooks) ? GREEN : GRAY;

                if (j < workingCooks && waitingPizzas > 0) {
                    Vector3 pizzaPosition = {cookPosition.x, cookPosition.y, cookPosition.z};
                    r.drawCube(pizzaPosition, 1.0f, 0.5f, 1.0f, RED);
                    cookPosition.y += 0.5;
                    --waitingPizzas;
                }

                r.drawCube(cookPosition, 1.0f, 0.5f, 1.0f, cookColor);
            }
        }
    }

    void Reception::updateCamera(float deltaTime)
    {
        if (_writingOrder)
            return;

        RaylibWrapper &r = RaylibWrapper::getInstance();
        float moveSpeed = 100.0f * deltaTime;
        float rotateSpeed = 30.0f * deltaTime;

        Vector3 direction = RaylibWrapper::vector3Subtract(_camera3D.target, _camera3D.position);
        direction = RaylibWrapper::vector3Normalize(direction);

        if (r.isKeyDown(KEY_S)) {
            _camera3D.position = RaylibWrapper::vector3Add(_camera3D.position, RaylibWrapper::vector3Scale(direction, -moveSpeed));
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(direction, -moveSpeed));
        }
        if (r.isKeyDown(KEY_W)) {
            _camera3D.position = RaylibWrapper::vector3Add(_camera3D.position, RaylibWrapper::vector3Scale(direction, moveSpeed));
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(direction, moveSpeed));
        }

        Vector3 right = RaylibWrapper::vector3CrossProduct(direction, _camera3D.up);
        right = RaylibWrapper::vector3Normalize(right);

        if (r.isKeyDown(KEY_A)) {
            _camera3D.position = RaylibWrapper::vector3Add(_camera3D.position, RaylibWrapper::vector3Scale(right, -moveSpeed));
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(right, -moveSpeed));
        }
        if (r.isKeyDown(KEY_D)) {
            _camera3D.position = RaylibWrapper::vector3Add(_camera3D.position, RaylibWrapper::vector3Scale(right, moveSpeed));
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(right, moveSpeed));
        }

        if (r.isKeyDown(KEY_SPACE)) {
            _camera3D.position.y += moveSpeed;
            _camera3D.target.y += moveSpeed;
        }
        if (r.isKeyDown(KEY_LEFT_CONTROL)) {
            _camera3D.position.y -= moveSpeed;
            _camera3D.target.y -= moveSpeed;
        }

        Vector3 up = RaylibWrapper::vector3CrossProduct(right, direction);
        up = RaylibWrapper::vector3Normalize(up);

        if (r.isKeyDown(KEY_UP))
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(up, rotateSpeed));
        if (r.isKeyDown(KEY_DOWN))
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(up, -rotateSpeed));
        if (r.isKeyDown(KEY_LEFT))
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(right, -rotateSpeed));
        if (r.isKeyDown(KEY_RIGHT))
            _camera3D.target = RaylibWrapper::vector3Add(_camera3D.target, RaylibWrapper::vector3Scale(right, rotateSpeed));
    }

    void Reception::processCommand(const std::string &command)
    {
        std::istringstream iss(command);
        std::string action;
        iss >> action;

        static std::unordered_map<std::string, std::function<void()>> actions = {
            {"exit", [this](){ CloseWindow(); }}
        };
        if (actions.contains(command))
            actions[command]();
        else
            placeOrder(command);
    }

    void Reception::placeOrder(const std::string &orderString)
    {
        std::istringstream iss(orderString);
        std::string order;

        while (std::getline(iss, order, ';'))
            processIndividualOrder(trim(order));
        dispatchKitchen();
    }

    void Reception::processIndividualOrder(const std::string &order)
    {
        std::istringstream iss(order);
        std::string type;
        std::string size;
        int quantity;
        char separator;

        if (!(iss >> type >> size >> separator >> quantity) || separator != 'X') {
            std::cerr << "Invalid order format: " << order << std::endl;
            return;
        }
        PizzaType pType = getPizzaType(type);
        PizzaSize pSize = getPizzaSize(size);
        if (pType == PizzaType::NoneType || pSize == PizzaSize::NoneSize)
            return;
        std::string newOrder = type + ":" + size;
        for (int i = 0; i < quantity; i++)
            _orders.push_back(newOrder);
    }

    PizzaType Reception::getPizzaType(std::string type)
    {
        return PizzaFactory::convertToPizzaType(type);
    }

    PizzaSize Reception::getPizzaSize(std::string size)
    {
        return PizzaFactory::convertToPizzaSize(size);
    }

    void Reception::dispatchKitchen()
    {
        plazza::Kitchen *lowest_kitchen;
        size_t lowest;

        if (_orders.empty())
            return;
        for (auto &order : _orders) {
            lowest = (size_t)_numCooksPerKitchen * 2;
            for (auto &kitchen : _kitchens) {
                size_t onGoing = kitchen->getOngoingOrders();
                if (onGoing < lowest) {
                    lowest = onGoing;
                    lowest_kitchen = kitchen.get();
                    break;
                }
            }
            if (lowest < (size_t)_numCooksPerKitchen * 2)
                lowest_kitchen->tryAddOrder(order);
            else {
                _kitchens.push_back(std::make_unique<Kitchen>(static_cast<size_t>(_numCooksPerKitchen), _multiplier, static_cast<size_t>(_restockTime)));
                _kitchens.back()->tryAddOrder(order);
                initializeKitchens();
            }
        }
        _orders.clear();
    }

    std::string Reception::trim(const std::string &str)
    {
        auto start = std::find_if_not(str.begin(), str.end(), [](int c) {
            return std::isspace(static_cast<unsigned char>(c));
        });

        auto end = std::find_if_not(str.rbegin(), str.rend(), [](int c) {
            return std::isspace(static_cast<unsigned char>(c));
        }).base();

        return (start < end) ? std::string(start, end) : std::string();
    }

    void Reception::removeClosedKitchens()
    {
        std::vector<std::unique_ptr<Kitchen>> _kitchensTemp;

        for (auto &kitchen : _kitchens)
            if (!kitchen->shouldBeClosed())
                _kitchensTemp.push_back(std::move(kitchen));
        _kitchens.clear();
        for (auto &kitchen : _kitchensTemp)
            _kitchens.push_back(std::move(kitchen));

        initializeKitchens();
    }
}
