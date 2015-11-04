#include "DeliverySvc.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class CustomerOrder {

public:
	CustomerOrder(int orderId, DeliverySvc * chosenDeliverySvc): orderId_(orderId), deliverSvc_(chosenDeliverySvc) {
		cout << " creating customer order\n\n";
	}

	void placeOrder() {
		cout << " placing order: " << orderId_;
		cout << " sending the order";
		deliverSvc_->sendPacket();
		auto trackingData_ = deliverSvc_->getTrackingInfo();
	}

private:
	int orderId_;
	DeliverySvc *deliverSvc_;
};

class DeliverySvcFactory {

public:
	static DeliverySvc* createDeliverSvc(int wt, int dist) {

		if (dist < 100 && wt < 10) {
			return new USPSDeliverysvc("Las Vegas", wt, 101);
		}
		else {
			return new FedexDeliverysvc("Los Angeles", wt, 102);
		}
	}
private:
};

int main_1() {

	DeliverySvc *bestDeliverySvc;
	int orderWt, destDist;

	cout << " enter order weight: ";
	cin >> orderWt;

	cout << " enter dest dist: ";
	cin >> destDist;

	std::srand(std::time(0)); // use current time as seed for random generator

	int orderId = std::rand();
	bestDeliverySvc = DeliverySvcFactory::createDeliverSvc(orderWt, destDist);
	CustomerOrder order(orderId, bestDeliverySvc);
	order.placeOrder();

	return 0;
}


















