#include "DeviceSimulator.hpp"

#include "BoostHttpsClient.hpp"

int main(int, char**)
{
    const std::string apiKey = "ApiKey ft0aiBWIiLTZspHjc3n8oL07lhsGh3FrGoFYLhVHjJs208uN0xoWZESNQRO7x8XuP+CsAP0fxx5H6Z3zB9J2O/fUFuXeL0ymjseAc/PmFvV8YUVEzZM7bdpOUGw5PXfU";

//    const std::string host = "edge.zhjixouahfpdviebd.com";
//    const int port = 443;

    const std::string host = "192.168.1.52";
    const int port = 14010;

    const std::string facadeCertPath = "../../../cpp/grpc_facade.crt";

    std::cout << "Staring Device simulation..." << std::endl;

    BoostHttpsClient core(host, port, apiKey);

    boost::asio::io_service ioService;

    DeviceSimulator simulator(ioService);
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
