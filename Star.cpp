
#include "Star.h"
#include <stdio.h>
#include <cstdlib>

Star::Star(){
    this->current_planets =  0;
    this->next_id = 0;
    planets  = NULL;
}

Star::~Star(){
  delete[] this->planets;

}

int Star::addPlanet(){
    Planet**p = new Planet*[current_planets+1]; // 1
    for (int i = 0 ; i < current_planets ; i++){
      p[i] = planets[i] ;
    }
    Planet* new_p = new Planet(rand() % 3000,next_id++); //3
    p [current_planets] = new_p ;
    current_planets++;
    delete [] planets;
    planets= p;
    return next_id-1;

}

bool Star::removePlanet(int id){
  Planet**p1 = new Planet*[current_planets-1];
  int b =0;
  if (getPlanet(id)== NULL){
        return false;

  }else{
      for (int i = 0 ; i < current_planets ; i++){

        if (planets[i]->getID() != id){
            p1[b+i] = planets[i];
        }else{
            b=-1;
            delete planets[i];
        }
      }
      current_planets--;
      delete [] planets;
      planets = p1;
      return true;

    }

}
Planet* Star::getPlanet(int id){
  for(int i=0;i<this->current_planets;i++){
    if(planets[i]->getID()==id){
      return planets[i];
    }
  }
  return NULL;
}


void Star:: orbit(){
    for (int i = 0 ; i< current_planets; i++){

        planets[i]->orbit();
    }

}
void Star::printStarInfo(){

    printf("The star currently has %d planets.\n" , current_planets );
    printf("Planets: \n");
    for (int i = 0; i < current_planets; i++) {

        printf("\tPlanet %c%d is %d million miles away at position %d around the star.\n",planets[i]->getType(),i, planets[i]->getDistance(), planets[i]->getPos());
    }
}
