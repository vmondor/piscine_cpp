/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:06:10 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/13 11:25:49 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

/*
int main()
{
    // Création d'une MateriaSource
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());      // Apprendre une Materia Ice
    src->learnMateria(new Cure());     // Apprendre une Materia Cure

    // Création d'un personnage
    ICharacter* me = new Character("me");

    // Création de Materias depuis MateriaSource
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Création d'un deuxième personnage
    ICharacter* bob = new Character("bob");

    // Utilisation des Materias équipées
    me->use(0, *bob); // Ice: " shoots an ice bolt at bob "
    me->use(1,*bob); // Cure: "* heals bob's wounds "

    // Test de l'équipement et du déclonage
    AMateria *newIce = src->createMateria("ice");
    me->equip(newIce);
    me->use(2, *bob); // Ice: " shoots an ice bolt at bob "

    // Test d'un emplacement plein
    AMateria *overflowMateria = src->createMateria("cure");
    me->equip(overflowMateria);
    AMateria* overflowMateria2 = src->createMateria("ice");
    me->equip(overflowMateria2); // message d'erreur car l'inventaire est plein

    // test pour unequip un materia et rajouter overflowMateria2
    me->unequip(3);
    me->equip(overflowMateria2); // marche

    // Test de l'utilisation d'une Materia qui n'existe pas (index invalide)
    me->use(4, *bob); // Rien ne se passe car il n'y a pas de Materia à cet index

    // Nettoyage mémoire
    delete bob;
    delete me;
    delete src;

    return 0;
}
*/
