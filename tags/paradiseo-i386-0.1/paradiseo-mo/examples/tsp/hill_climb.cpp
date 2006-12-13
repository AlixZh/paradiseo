// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

// "hill_climb.cpp"

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

#include <moHC.h>
#include <moFirstImprSelect.h>
#include <moBestImprSelect.h>
#include <moRandImprSelect.h>

#include "share/graph.h"
#include "share/route.h"
#include "share/route_eval.h"
#include "share/route_init.h"

#include "share/two_opt.h"
#include "share/two_opt_init.h"
#include "share/two_opt_next.h"
#include "share/two_opt_incr_eval.h"

int main (int __argc, char * __argv []) {

  if (__argc != 2) {
    
    std :: cerr << "Usage : ./hill_climb [instance]" << std :: endl ;
    return 1 ;
  }

  srand (1000) ;

  Graph :: load (__argv [1]) ; // Instance

  Route route ; // Solution
  
  RouteInit init ; // Sol. Random Init.
  init (route) ;

  RouteEval full_eval ; // Full. Eval.
  full_eval (route) ;
  
  std :: cout << "[From] " << route << std :: endl ;

  /* Tools for an efficient (? :-))
     local search ! */
  
  TwoOptInit two_opt_init ; // Init.
   
  TwoOptNext two_opt_next ; // Explorer.
  
  TwoOptIncrEval two_opt_incr_eval ; // Eff. eval.
  
  //moFirstImprSelect <TwoOpt> two_opt_select ;
  moBestImprSelect <TwoOpt> two_opt_select ;
  //moRandImprSelect <TwoOpt> two_opt_select ;

  moHC <TwoOpt> hill_climb (two_opt_init, two_opt_next, two_opt_incr_eval, two_opt_select, full_eval) ;
  hill_climb (route) ;

  std :: cout << "[To] " << route << std :: endl ;

  return 0 ;
}

