#include "PilotSimulator.hpp"

#include "AsioHttpsClient.hpp"

int main(int, char**)
{
    const std::string host = "192.168.56.1";
    const int port = 14010;

    const std::string apiKey = "";

    const std::string facadeCertPath = "../../../cpp/grpc_facade.crt";

    std::cout << "Staring Pilot simulation..." << std::endl;

    AsioHttpsClient core(host, port, apiKey);

    PilotSimulator simulator;
    simulator.start(core, facadeCertPath);

    std::cout << " >>>>>>> DONE <<<<<<<" << std::endl;
    return 0;
}
