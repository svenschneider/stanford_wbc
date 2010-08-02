/*
 * Stanford Whole-Body Control Framework http://stanford-wbc.sourceforge.net/
 *
 * Copyright (c) 2010 Stanford University. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 */

/**
   \file jspace/State.hpp
   \author Roland Philippsen
*/

#ifndef JSPACE_STATE_HPP
#define JSPACE_STATE_HPP

#include <vector>

namespace jspace {
  
  class State
  {
  public:
    typedef enum {
      COMPARE_ACQUISITION_TIME = 0x1,
      COMPARE_POSITION         = 0x2,
      COMPARE_VELOCITY         = 0x4,
      COMPARE_FORCE            = 0x8,
      COMPARE_ALL              = 0xf
    } compare_flags_t;
    
    State();
    State(State const & orig);
    State(size_t npos, size_t nvel, size_t nforce);
    
    /**
       Resizes and zeros-out position_, velocity_, and force_ to the
       desired lengths. Also sets the timestamp to zero.
    */
    void init(size_t npos, size_t nvel, size_t nforce);
    
    bool equal(State const & rhs,
	       int flags = COMPARE_POSITION | COMPARE_VELOCITY,
	       double precision = 1e-3) const;
    
    State & operator = (State const & rhs);
    
    size_t time_sec_;
    size_t time_usec_;
    std::vector<double> position_;
    std::vector<double> velocity_;
    std::vector<double> force_;
  };
  
}

#endif // JSPACE_STATE_HPP
