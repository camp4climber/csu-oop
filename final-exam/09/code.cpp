Class Transportation() { ... }

Class ElectricPoweredTransportation() : public Transportation { ... }

Class Car() : public Transportation { ... }

Class Tesla_ModelS() : public ElectricPoweredTransportation, public Car { ... }
