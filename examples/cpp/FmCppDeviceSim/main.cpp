#include "DeviceSimulator.hpp"

#include "AsioHttpsClient.hpp"

int main(int, char**)
{
    const std::string host = "192.168.56.1";
    const int port = 14010;

    const std::string apiKey = "";

    const std::string facadeCertPath = "../../../cpp/grpc_facade.crt";


    AsioHttpsClient core(host, port, apiKey);

    DeviceSimulator simulator;
    simulator.start(core, facadeCertPath);

    while (not simulator.isDone())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    std::cout << " >>>>>>> DONE <<<<<<<" << std::endl;
    return 0;
}
