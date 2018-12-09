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

    boost::asio::io_service ioService;

    PilotSimulator simulator(ioService);
    simulator.start(core, facadeCertPath);

    while (not simulator.isDone())
    {
        try
        {
            ioService.run();
        }
        catch (const std::exception& e)
        {
            std::cout << "Task execution error: " << e.what() << std::endl;
        }
    }

    std::cout << " >>>>>>> DONE <<<<<<<" << std::endl;
    return 0;
}
