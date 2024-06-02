/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** RaylibWrapper
*/

#include "RaylibWrapper.hpp"

RaylibWrapper &RaylibWrapper::getInstance()
{
    static RaylibWrapper instance;
    return instance;
}

void RaylibWrapper::init(int screenWidth, int screenHeight, const std::string &title)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
}

void RaylibWrapper::close()
{
    CloseWindow();
}

bool RaylibWrapper::shouldClose() const
{
    return WindowShouldClose();
}

void RaylibWrapper::beginDrawing() const
{
    BeginDrawing();
}

void RaylibWrapper::endDrawing() const
{
    EndDrawing();
}

void RaylibWrapper::clearBackground(Color color) const
{
    ClearBackground(color);
}

void RaylibWrapper::setWindowTitle(const std::string &title) const
{
    SetWindowTitle(title.c_str());
}

void RaylibWrapper::drawText(const std::string &text, int x, int y, int fontSize, Color color) const
{
    DrawText(text.c_str(), x, y, fontSize, color);
}

void RaylibWrapper::drawRectangle(int posX, int posY, int width, int height, Color color) const
{
    DrawRectangle(posX, posY, width, height, color);
}

void RaylibWrapper::drawRectangle(Rectangle &rect, Color color) const
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
}

Rectangle RaylibWrapper::createRectangle(int posX, int posY, int width, int height, Color color) const
{
    Rectangle rect;
    rect.x = posX;
    rect.y = posY;
    rect.width = width;
    rect.height = height;

    return rect;
}

void RaylibWrapper::drawTextureOnRectangle(const Rectangle &rect, const Texture2D &texture, const Color &tint) const
{
    Rectangle srcRect = { 0.0f, 0.0f, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    DrawTextureRec(texture, srcRect, { rect.x, rect.y }, tint);
}

void RaylibWrapper::drawCircle(int centerX, int centerY, float radius, Color color) const
{
    DrawCircle(centerX, centerY, radius, color);
}

bool RaylibWrapper::isKeyPressed(int key) const
{
    return IsKeyPressed(key);
}

bool RaylibWrapper::isKeyDown(int key) const
{
    return IsKeyDown(key);
}

void RaylibWrapper::beginMode3D(Camera3D &camera) const
{
    BeginMode3D(camera);
}

void RaylibWrapper::endMode3D() const
{
    EndMode3D();
}

void RaylibWrapper::drawModel(Model model, Vector3 position, float scale, Color tint) const
{
    DrawModel(model, position, scale, tint);
}

void RaylibWrapper::drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) const
{
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void RaylibWrapper::drawGrid(int slices, float spacing) const
{
    DrawGrid(slices, spacing);
}

Camera RaylibWrapper::createCamera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection) const
{
    Camera camera;
    camera.position = position;
    camera.target = target;
    camera.up = up;
    camera.fovy = fovy;
    camera.projection = projection;
    return camera;
}

void RaylibWrapper::updateCamera(Camera *camera, int mode) const
{
    UpdateCamera(camera, mode);
}

Model RaylibWrapper::loadModel(const std::string &filename) const
{
    return LoadModel(filename.c_str());
}

void RaylibWrapper::unloadModel(Model model) const
{
    UnloadModel(model);
}

float RaylibWrapper::getDeltaTime() const
{
    return GetFrameTime();
}

RaylibWrapper::~RaylibWrapper()
{
    close();
}

void RaylibWrapper::drawCube(Vector3 position, float width, float height, float length, Color color) const
{
    DrawCube(position, width, height, length, color);
}

int RaylibWrapper::getScreenWidth() const
{
    return GetScreenWidth();
}

int RaylibWrapper::getScreenHeight() const
{
    return GetScreenHeight();
}

int RaylibWrapper::measureText(const std::string text, int fontSize) const
{
    return MeasureText(text.c_str(), fontSize);
}

int RaylibWrapper::getKeyPressed() const
{
    return GetKeyPressed();
}

float RaylibWrapper::vector3DistanceSquared(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3DistanceSqr(v1, v2);
}

Vector3 RaylibWrapper::vector3Subtract(Vector3 v1, Vector3 v2)
{
    return Vector3Subtract(v1, v2);
}

Vector3 RaylibWrapper::vector3Add(Vector3 v1, Vector3 v2)
{
    return Vector3Add(v1, v2);
}

Vector3 RaylibWrapper::vector3Scale(Vector3 v, float scale)
{
    return Vector3Scale(v, scale);
}

Vector3 RaylibWrapper::vector3Normalize(Vector3 v)
{
    return Vector3Normalize(v);
}

Vector3 RaylibWrapper::vector3CrossProduct(Vector3 v1, Vector3 v2)
{
    return Vector3CrossProduct(v1, v2);
}

float RaylibWrapper::vector3Length(const Vector3 &v)
{
    return Vector3Length(v);
}
