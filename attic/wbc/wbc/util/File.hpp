/*
 * Stanford Whole-Body Control Framework http://stanford-wbc.sourceforge.net/
 *
 * Copyright (c) 1997-2009 Stanford University. All rights reserved.
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
   \file File.hpp Utility for wrapping a FILE*, and closing it at destruction time.
   \author Roland Philippsen
   \note Originally Copyright (c) 2008 Roland Philippsen, released under a BSD license.
*/

#ifndef WBC_UTIL_FILE_HPP
#define WBC_UTIL_FILE_HPP

#include <stdexcept>

extern "C" {
#include <stdio.h>
}

namespace wbc {

  /**
     Wraps a FILE*, closing it in the destructor.
  */
  class File
  {
  public:
    File(char const * path, char const * mode) throw (std::runtime_error);
    ~File();
    
    FILE* stream;
  };

}

#endif // WBC_UTIL_FILE_HPP
