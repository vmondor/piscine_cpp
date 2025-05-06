/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/01 13:02:55 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Créer un objet Data
    Data myData = {1, "Test Object"};

    // Sérialiser l'adresse de myData
    uintptr_t serialized = Serializer::serialize(&myData);

    // Désérialiser pour récupérer le pointeur vers l'objet Data
    Data* deserialized = Serializer::deserialize(serialized);

    // Vérifier que les deux pointeurs pointent vers le même objet
    if (deserialized == &myData) {
        std::cout << "La sérialisation et la désérialisation ont réussi !" << std::endl;
        std::cout << "ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;
    } else {
        std::cout << "Erreur lors de la sérialisation ou de la désérialisation." << std::endl;
    }
    return 0;
}