mkdir -p generated
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/add_channels.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/attach_channels.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/channel.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/channel_validation.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/connection_state.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/handover_data.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/location.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/common/role.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/core/attach.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/core/list_devices.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/core/operate.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/facade/control/facade_service.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/facade/control/heartbeat.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/facade/control/setup.proto
