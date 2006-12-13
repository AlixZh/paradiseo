// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

// "route_eval.cpp"

// (c) OPAC Team, LIFL, 2003

/* This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
   
   Contact: cahon@lifl.fr
*/

#include "route_eval.h"
#include "graph.h"

void RouteEval :: operator () (Route & __route) {
  
  float len = 0 ;
  
  for (unsigned i = 0 ; i < Graph :: size () ; i ++)
    len -= Graph :: distance (__route [i], __route [(i + 1) % Graph :: size ()]) ; 
  
  __route.fitness (len) ;
}
