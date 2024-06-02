/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD12-florent.guittre
** File description:
** Toy.hpp
*/

#ifndef B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
    #define B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <exception>

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY,
    };
    class Error {
    public:
        Error();
        Error(const std::string &location);
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };
        const char *what() const noexcept;
        std::string where() const;
        ErrorType type = UNKNOWN;
        std::string _location = "";
    };
    Toy();
    Toy(ToyType type, const std::string &name, const std::string &file);
    Toy(const Toy &toy);
    ~Toy();
    Toy::ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    virtual void speak(const std::string &message);
    virtual bool speak_es(const std::string &message);
    Error getLastError();
    Toy &operator=(const Toy &toy);
    Toy &operator<<(const std::string &message);
protected:
    void setLastError(const std::string &location, Toy::Error::ErrorType type);
    Toy::ToyType _type = Toy::ToyType::BASIC_TOY;
    std::string _name = "toy";
    std::string _picture = "";
    Error *lastError = new Error;
};

static std::ostream &operator<<(std::ostream &out, const Toy &toy)
{
    return out << toy.getName() << std::endl << toy.getAscii() << std::endl;
}

#endif //B_PDG_300_STG_3_1_PDGD12_FLORENT_GUITTRE_TOY_HPP
