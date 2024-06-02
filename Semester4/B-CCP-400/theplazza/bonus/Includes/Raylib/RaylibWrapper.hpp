/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** RaylibWrapper
*/

#ifndef RAYLIBWRAPPER_H
    #define RAYLIBWRAPPER_H

    #include <raylib.h>
    #include <raymath.h>
    #include <rlgl.h>
    #include <string>
    #include <unordered_map>
    #include <memory>
    #include <cmath>
    #include <vector>
    #include <functional>
    #include <cstring>
    #include <iostream>

class RaylibWrapper {
    public:
        static RaylibWrapper &getInstance();

        RaylibWrapper(const RaylibWrapper&) = delete;
        RaylibWrapper &operator=(const RaylibWrapper&) = delete;

        void init(int screenWidth, int screenHeight, const std::string &title);
        void close();

        bool shouldClose() const;
        void beginDrawing() const;
        void endDrawing() const;
        void clearBackground(Color color) const;
        void setWindowTitle(const std::string &title) const;

        void drawText(const std::string &text, int x, int y, int fontSize, Color color) const;
        void drawRectangle(int posX, int posY, int width, int height, Color color) const;
        void drawRectangle(Rectangle &rect, Color color) const;
        Rectangle createRectangle(int posX, int posY, int width, int height, Color color) const;
        void drawTextureOnRectangle(const Rectangle &rect, const Texture2D &texture, const Color &tint) const;
        void drawCircle(int centerX, int centerY, float radius, Color color) const;

        bool isKeyPressed(int key) const;
        bool isKeyDown(int key) const;

        void beginMode3D(Camera3D &camera) const;
        void endMode3D() const;

        void drawModel(Model model, Vector3 position, float scale, Color tint) const;
        void drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) const;
        void drawGrid(int slices, float spacing) const;

        Camera createCamera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection) const;
        void updateCamera(Camera *camera, int mode) const;

        Model loadModel(const std::string &filename) const;
        void unloadModel(Model model) const;

        float getDeltaTime() const;

        void drawCube(Vector3 position, float width, float height, float length, Color color) const;

        int getScreenWidth() const;
        int getScreenHeight() const;

        int measureText(const std::string text, int fontSize) const;
        int getKeyPressed() const;

        static float vector3DistanceSquared(const Vector3 &v1, const Vector3 &v2);
        static Vector3 vector3Subtract(Vector3 v1, Vector3 v2);
        static Vector3 vector3Add(Vector3 v1, Vector3 v2);
        static Vector3 vector3Scale(Vector3 v, float scale);
        static Vector3 vector3Normalize(Vector3 v);
        static Vector3 vector3CrossProduct(Vector3 v1, Vector3 v2);
        static float vector3Length(const Vector3 &v);

    private:
        RaylibWrapper() = default;
        ~RaylibWrapper();
};

#endif /*!RAYLIBWRAPPER_H*/
