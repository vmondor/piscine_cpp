/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:12:12 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 18:26:38 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(Brain const& src);
        Brain& operator=(Brain const& src);
        ~Brain();
        std::string ideas[100];
};