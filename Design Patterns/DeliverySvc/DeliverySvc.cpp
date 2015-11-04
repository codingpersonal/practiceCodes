
#include "DeliverySvc.h"
#include <iostream>

using namespace std;

USPSDeliverysvc::USPSDeliverysvc(std::string dest, int packetWeight, int packetId) {
	cout << "creating usps object\n";
}

void USPSDeliverysvc::sendPacket() {
	cout << " sending through USPS\n";
}

TrackingData USPSDeliverysvc::getTrackingInfo() {

	cout << " getting tracking data from USPS\n";
	return TrackingData();
}


void FedexDeliverysvc::sendPacket() {
	cout << " sending through Fedex\n";
}

TrackingData FedexDeliverysvc::getTrackingInfo() {

	cout << " getting tracking data from Fedex\n";
	return TrackingData();
}

FedexDeliverysvc::FedexDeliverysvc(std::string dest, int packetWeight, int packetId) {
	cout << " constructing fedex obj\n";
}



