/*
** EPITECH PROJECT, 2021
** day13
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &filename): Toy(Toy::BUZZ, name, filename)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
}