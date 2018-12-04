mkdir -p generated
protoc -I ../proto --cpp_out=generated ../proto/common/add_channels.proto
protoc -I ../proto --cpp_out=generated ../proto/common/attach_channels.proto
protoc -I ../proto --cpp_out=generated ../proto/common/channel.proto
protoc -I ../proto --cpp_out=generated ../proto/common/channel_validation.proto
protoc -I ../proto --cpp_out=generated ../proto/common/connection_state.proto
protoc -I ../proto --cpp_out=generated ../proto/common/handover_data.proto
protoc -I ../proto --cpp_out=generated ../proto/common/location.proto
protoc -I ../proto --cpp_out=generated ../proto/common/role.proto
protoc -I ../proto --cpp_out=generated ../proto/core/attach.proto
protoc -I ../proto --cpp_out=generated ../proto/core/list_devices.proto
protoc -I ../proto --cpp_out=generated ../proto/core/operate.proto
protoc -I ../proto --cpp_out=generated ../proto/facade/control/heartbeat.proto
protoc -I ../proto --cpp_out=generated ../proto/facade/control/setup.proto
protoc -I ../proto --grpc_out=generated --cpp_out=generated --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin ../proto/facade/control/facade_service.proto
