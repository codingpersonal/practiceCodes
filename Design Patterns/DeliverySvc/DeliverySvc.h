#pragma once

#include <iostream>

using namespace std;

struct TrackingData
{
	std::string currLocation;
	int estimatedHoursToDeliver;
};

class DeliverySvc {

public:
	virtual void sendPacket() = 0;
	virtual TrackingData getTrackingInfo() = 0;

private:

};


class USPSDeliverysvc : public DeliverySvc{
public:
	USPSDeliverysvc(std::string dest, int packetWeight, int packetId);
	void sendPacket() override;
	TrackingData getTrackingInfo() override;
};


class FedexDeliverysvc : public DeliverySvc {
public:
	FedexDeliverysvc(std::string dest, int packetWeight, int packetId);
	void sendPacket() override;
	TrackingData getTrackingInfo() override;
};










