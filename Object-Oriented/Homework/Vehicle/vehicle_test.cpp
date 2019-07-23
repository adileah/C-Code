/*    @file vehicle_test.cpp   
      @author Adileah Smith
      @date Jun 17 2018

			@description Tests for the classes in the vehicle.h file:
			Bicycle, Car, Truck, Airplane
*/

#include "gtest/gtest.h"

#include "vehicle.h"

TEST(truck,color){
  Truck a;
  a.setColor("green");
  EXPECT_EQ(a.getColor(), "green");
}
TEST(car,air){
  Car a;
  a.setAir(false);
  EXPECT_EQ(a.getAir(), false);
}
TEST(airplane,props){
  Airplane a;
  a.setProps(2);
  EXPECT_EQ(a.getProps(), 2);
}
TEST(bike,year){
  Bike a;
  a.setYear(1989);
  EXPECT_EQ(a.getYear(), 1989);
}
TEST(bike,constructor){
  Bike a;
  EXPECT_EQ(a.getWheels(), 2);
}
TEST(truck, price){
  Truck a;
  EXPECT_EQ(a.getPrice(), 16250);
}
TEST(car, price){
  Car a;
  EXPECT_EQ(a.getPrice(), 19000);
}
TEST(airplane, price){
  Airplane a;
  EXPECT_EQ(a.getPrice(), 56550);
}
TEST(bike, price){
  Bike a;
  EXPECT_EQ(a.getPrice(), 800);
}
TEST(truck, setwheels){
  Truck a;
  a.setWheels(9);
  EXPECT_EQ(a.getWheels(), 9);
}
TEST(airplane, props2){
  Airplane a;
  a.setProps(9);
  EXPECT_EQ(a.getProps(), 9);
}
TEST(airplane, props3){
  Airplane a;
  EXPECT_EQ(a.getProps(), 3);
}
TEST(bike, color){
  Bike a;
  EXPECT_EQ(a.getColor(), "green");
}
TEST(car, color){
  Car a;
  a.setColor("Purple");
  EXPECT_EQ(a.getColor(), "Purple");
}
TEST(truck, price2){
  Truck a;
  a.setYear(1400);
  EXPECT_EQ(a.getPrice(), 200);
}
TEST(car, price2){
  Car a;
  a.setYear(1400);
  EXPECT_EQ(a.getPrice(), 100);
}
TEST(airplane, price2){
  Airplane a;
  a.setYear(1400);
  EXPECT_EQ(a.getPrice(), 1000);
}
TEST(bike, price2){
  Bike a;
  a.setYear(1400);
  EXPECT_EQ(a.getPrice(), 0);
}
TEST(car, air1){
  Car a;
  a.setAir(true);
  EXPECT_EQ(a.getPrice(), 19200);
}
TEST(car, dvd){
  Car a;
  a.setDvd(true);
  EXPECT_EQ(a.getPrice(), 19100);
}