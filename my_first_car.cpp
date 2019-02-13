// Skeleton code : Andrew Way
// filled in by: Michael Wright
// Date: Feb 04, 2018

#include <iostream>
using namespace std;

class Tire {
	//TODO Implement the tire class
	protected:
    	float weight_;
	public:
		Tire(float w) 
		: weight_(w) 
		{}
		
		float weight(void) const {return weight_;}
};

class BridgeStoneTire : public Tire {
	/*
		TODO
		Implement a BridgeStoneTire class. 
		It extends the Tire class. 
		The BridgeStoneTire class is just a Tire with weight 12Kg.
	*/
	public:
  		BridgeStoneTire (int w = 12)
    	: Tire(w)
  		{}
};

class Motor {
	/*
    	TODO
    	Implement the motor class
	*/
	private:
		float weight_;
		float base_fuel_efficiency_;
	public:
		Motor (float w, float f)
		: weight_(w), base_fuel_efficiency_(f)
		{}
		
    	float weight(void) const {return weight_;}
    	float base_fuel_efficiency(void) const {return base_fuel_efficiency_;}
};

class Chassis {
	/*
		TODO
		Create and implement the Chassis class
	*/
	private:
		float weight_;
	public:
		Chassis(float w)
		: weight_(w)
		{}
		
	float weight(void) const {return weight_;}
};

class Car {

	private:
		Chassis chassis_;
	    Tire tire1_;
	    Tire tire2_;
	    Tire tire3_;
	    Tire tire4_;
	    Motor motor_;
	    float fuel_;   //Litres
	  
	public:
	    Car(Chassis c, Motor m, Tire t1, Tire t2,Tire t3, Tire t4) 
		: chassis_(c),motor_(m),tire1_(t1), tire2_(t2),tire3_(t3),tire4_(t4) 
		{
	      set_fuel(0);
	    }
    /*
    	TODO
    	Implement the weight() function. It the returns the sum of the weights of all of its components. 
    */
    	float weight(void) const; //implemented below the Car class
  
    //Calculates fuel efficiency in Km/L
    	float fuel_efficiency(){
    		return motor_.base_fuel_efficiency()*(1000/weight());
   		}
  
    //Calculates distance driven by injecting X litres of fuel into the engine
    //Removes that amount of fuel from the fuel tank if enough exists.
    	float drive(float fuel_injected){
      		float distance_driven;
      		if(fuel_injected<=fuel_){
        		distance_driven=fuel_efficiency()*fuel_injected;
       			fuel_=fuel_-fuel_injected;
      		}
      		else {
        		distance_driven=fuel_efficiency()*fuel_;
        		fuel_=0;
      		}
      		return distance_driven;
    	}
    
    	void set_fuel(float fuel_){
      		this->fuel_=fuel_;
    	}
    /*
    	TODO
    	Implement the hasFuel function. Returns true if fuel is greater than 0. Else, returns false. 
    */
    	bool hasFuel (void) const; // implemented below the Car class
};

// weight and hasFuel functions for the Car class implemented here to improve readability
float Car::weight(void) const {
	return tire1_.weight() + tire2_.weight() + tire3_.weight() + tire4_.weight() + motor_.weight() + chassis_.weight();
}
bool Car::hasFuel(void) const {
	if (fuel_ > 0) { return true;}
	else {return false;}
}


// Main function for the program
int main() {

	cout << "Constructing car..." << endl;
 
	//Build the chassis
	Chassis chassis_(1000);
	  
	cout << "Chassis weight: " << chassis_.weight() << endl; 
	 
	//Build the wheels
	/*
		TODO
	    Initialize four bridgestone tires.
	*/
	BridgeStoneTire tire1_, tire2_, tire3_, tire4_;
	  
	/*
	    TODO
	    Print out each of the tires weights. The weights are in Kg
	*/
	cout << "Tire weights: " << endl <<  "tire 1: "  << tire1_.weight() << "kg" << endl;
	cout <<  "tire 2: " << tire2_.weight() << "kg" << endl;
	cout <<  "tire 3: " << tire3_.weight() << "kg" << endl;
	cout <<  "tire 4: " << tire4_.weight() << "kg" << endl;
	
	
	//Init the motor
	Motor motor_(200,9.4);
	  
	cout << "Motor weight: " << motor_.weight() << "Kg" << endl;
	cout << "Motor base efficiency " << motor_.base_fuel_efficiency() << "Km/L" << endl;
	 
	 
	//Stick all the components together 
	/*
		TODO
	    Call the Car Constructor and create a car object.
	    The arguments of the constructor will be the objects you just created.
	*/
	Car car(chassis_,motor_, tire1_, tire2_, tire3_, tire4_);
	
	cout << "Total car weight: " << car.weight() << "Kg" << endl;
	cout << "Car fuel efficiency: " << car.fuel_efficiency() << "Km/L" << endl;
	  
	//Fuel up the car
	car.set_fuel(45);//Add 45L of gas to the tank
	  
	float distance_driven=0;
	float total_distance_driven=0;
	  
	//Test drive!
	while(car.hasFuel()){
		distance_driven = car.drive(10);
		total_distance_driven=total_distance_driven+distance_driven;
		cout << "Drove "<<distance_driven<<"Km..."<<endl;
	}
	cout <<"Uh oh! Out of gas."<<endl;
	cout <<"Total trip distance: "<<total_distance_driven<<endl;
	
	return 0;
}