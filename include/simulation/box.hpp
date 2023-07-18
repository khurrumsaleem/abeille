/*
 * Abeille Monte Carlo Code
 * Copyright 2019-2023, Hunter Belanger
 * Copyright 2021-2022, Commissariat à l'Energie Atomique et aux Energies
 * Alternatives
 *
 * hunter.belanger@gmail.com
 *
 * This file is part of the Abeille Monte Carlo code (Abeille).
 *
 * Abeille is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Abeille is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Abeille. If not, see <https://www.gnu.org/licenses/>.
 *
 * */
#ifndef BOX_H
#define BOX_H

#include <simulation/spatial_distribution.hpp>

class Box : public SpatialDistribution {
 public:
  Box(Position low, Position hi);

  Position sample(pcg32& rng) const override final;

  Position low() const { return low_; }
  Position hi() const { return hi_; }

 private:
  Position low_, hi_;
};

std::shared_ptr<Box> make_box_distribution(const YAML::Node& node);

#endif
