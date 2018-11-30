package com.fleetmgr.interfaces.facade.control;

import static io.grpc.MethodDescriptor.generateFullMethodName;
import static io.grpc.stub.ClientCalls.asyncBidiStreamingCall;
import static io.grpc.stub.ClientCalls.asyncClientStreamingCall;
import static io.grpc.stub.ClientCalls.asyncServerStreamingCall;
import static io.grpc.stub.ClientCalls.asyncUnaryCall;
import static io.grpc.stub.ClientCalls.blockingServerStreamingCall;
import static io.grpc.stub.ClientCalls.blockingUnaryCall;
import static io.grpc.stub.ClientCalls.futureUnaryCall;
import static io.grpc.stub.ServerCalls.asyncBidiStreamingCall;
import static io.grpc.stub.ServerCalls.asyncClientStreamingCall;
import static io.grpc.stub.ServerCalls.asyncServerStreamingCall;
import static io.grpc.stub.ServerCalls.asyncUnaryCall;
import static io.grpc.stub.ServerCalls.asyncUnimplementedStreamingCall;
import static io.grpc.stub.ServerCalls.asyncUnimplementedUnaryCall;

/**
 */
@javax.annotation.Generated(
    value = "by gRPC proto compiler (version 1.13.1)",
    comments = "Source: facade/control/facade_service.proto")
public final class FacadeServiceGrpc {

  private FacadeServiceGrpc() {}

  public static final String SERVICE_NAME = "com.fleetmgr.interfaces.facade.control.FacadeService";

  // Static method descriptors that strictly reflect the proto.
  private static volatile io.grpc.MethodDescriptor<com.fleetmgr.interfaces.facade.control.ClientMessage,
      com.fleetmgr.interfaces.facade.control.ControlMessage> getControlMethod;

  public static io.grpc.MethodDescriptor<com.fleetmgr.interfaces.facade.control.ClientMessage,
      com.fleetmgr.interfaces.facade.control.ControlMessage> getControlMethod() {
    io.grpc.MethodDescriptor<com.fleetmgr.interfaces.facade.control.ClientMessage, com.fleetmgr.interfaces.facade.control.ControlMessage> getControlMethod;
    if ((getControlMethod = FacadeServiceGrpc.getControlMethod) == null) {
      synchronized (FacadeServiceGrpc.class) {
        if ((getControlMethod = FacadeServiceGrpc.getControlMethod) == null) {
          FacadeServiceGrpc.getControlMethod = getControlMethod = 
              io.grpc.MethodDescriptor.<com.fleetmgr.interfaces.facade.control.ClientMessage, com.fleetmgr.interfaces.facade.control.ControlMessage>newBuilder()
              .setType(io.grpc.MethodDescriptor.MethodType.BIDI_STREAMING)
              .setFullMethodName(generateFullMethodName(
                  "com.fleetmgr.interfaces.facade.control.FacadeService", "control"))
              .setSampledToLocalTracing(true)
              .setRequestMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  com.fleetmgr.interfaces.facade.control.ClientMessage.getDefaultInstance()))
              .setResponseMarshaller(io.grpc.protobuf.ProtoUtils.marshaller(
                  com.fleetmgr.interfaces.facade.control.ControlMessage.getDefaultInstance()))
                  .setSchemaDescriptor(new FacadeServiceMethodDescriptorSupplier("control"))
                  .build();
          }
        }
     }
     return getControlMethod;
  }

  /**
   * Creates a new async stub that supports all call types for the service
   */
  public static FacadeServiceStub newStub(io.grpc.Channel channel) {
    return new FacadeServiceStub(channel);
  }

  /**
   * Creates a new blocking-style stub that supports unary and streaming output calls on the service
   */
  public static FacadeServiceBlockingStub newBlockingStub(
      io.grpc.Channel channel) {
    return new FacadeServiceBlockingStub(channel);
  }

  /**
   * Creates a new ListenableFuture-style stub that supports unary calls on the service
   */
  public static FacadeServiceFutureStub newFutureStub(
      io.grpc.Channel channel) {
    return new FacadeServiceFutureStub(channel);
  }

  /**
   */
  public static abstract class FacadeServiceImplBase implements io.grpc.BindableService {

    /**
     */
    public io.grpc.stub.StreamObserver<com.fleetmgr.interfaces.facade.control.ClientMessage> control(
        io.grpc.stub.StreamObserver<com.fleetmgr.interfaces.facade.control.ControlMessage> responseObserver) {
      return asyncUnimplementedStreamingCall(getControlMethod(), responseObserver);
    }

    @java.lang.Override public final io.grpc.ServerServiceDefinition bindService() {
      return io.grpc.ServerServiceDefinition.builder(getServiceDescriptor())
          .addMethod(
            getControlMethod(),
            asyncBidiStreamingCall(
              new MethodHandlers<
                com.fleetmgr.interfaces.facade.control.ClientMessage,
                com.fleetmgr.interfaces.facade.control.ControlMessage>(
                  this, METHODID_CONTROL)))
          .build();
    }
  }

  /**
   */
  public static final class FacadeServiceStub extends io.grpc.stub.AbstractStub<FacadeServiceStub> {
    private FacadeServiceStub(io.grpc.Channel channel) {
      super(channel);
    }

    private FacadeServiceStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected FacadeServiceStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new FacadeServiceStub(channel, callOptions);
    }

    /**
     */
    public io.grpc.stub.StreamObserver<com.fleetmgr.interfaces.facade.control.ClientMessage> control(
        io.grpc.stub.StreamObserver<com.fleetmgr.interfaces.facade.control.ControlMessage> responseObserver) {
      return asyncBidiStreamingCall(
          getChannel().newCall(getControlMethod(), getCallOptions()), responseObserver);
    }
  }

  /**
   */
  public static final class FacadeServiceBlockingStub extends io.grpc.stub.AbstractStub<FacadeServiceBlockingStub> {
    private FacadeServiceBlockingStub(io.grpc.Channel channel) {
      super(channel);
    }

    private FacadeServiceBlockingStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected FacadeServiceBlockingStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new FacadeServiceBlockingStub(channel, callOptions);
    }
  }

  /**
   */
  public static final class FacadeServiceFutureStub extends io.grpc.stub.AbstractStub<FacadeServiceFutureStub> {
    private FacadeServiceFutureStub(io.grpc.Channel channel) {
      super(channel);
    }

    private FacadeServiceFutureStub(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      super(channel, callOptions);
    }

    @java.lang.Override
    protected FacadeServiceFutureStub build(io.grpc.Channel channel,
        io.grpc.CallOptions callOptions) {
      return new FacadeServiceFutureStub(channel, callOptions);
    }
  }

  private static final int METHODID_CONTROL = 0;

  private static final class MethodHandlers<Req, Resp> implements
      io.grpc.stub.ServerCalls.UnaryMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ServerStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.ClientStreamingMethod<Req, Resp>,
      io.grpc.stub.ServerCalls.BidiStreamingMethod<Req, Resp> {
    private final FacadeServiceImplBase serviceImpl;
    private final int methodId;

    MethodHandlers(FacadeServiceImplBase serviceImpl, int methodId) {
      this.serviceImpl = serviceImpl;
      this.methodId = methodId;
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public void invoke(Req request, io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        default:
          throw new AssertionError();
      }
    }

    @java.lang.Override
    @java.lang.SuppressWarnings("unchecked")
    public io.grpc.stub.StreamObserver<Req> invoke(
        io.grpc.stub.StreamObserver<Resp> responseObserver) {
      switch (methodId) {
        case METHODID_CONTROL:
          return (io.grpc.stub.StreamObserver<Req>) serviceImpl.control(
              (io.grpc.stub.StreamObserver<com.fleetmgr.interfaces.facade.control.ControlMessage>) responseObserver);
        default:
          throw new AssertionError();
      }
    }
  }

  private static abstract class FacadeServiceBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoFileDescriptorSupplier, io.grpc.protobuf.ProtoServiceDescriptorSupplier {
    FacadeServiceBaseDescriptorSupplier() {}

    @java.lang.Override
    public com.google.protobuf.Descriptors.FileDescriptor getFileDescriptor() {
      return com.fleetmgr.interfaces.facade.control.FacadeServiceOuterClass.getDescriptor();
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.ServiceDescriptor getServiceDescriptor() {
      return getFileDescriptor().findServiceByName("FacadeService");
    }
  }

  private static final class FacadeServiceFileDescriptorSupplier
      extends FacadeServiceBaseDescriptorSupplier {
    FacadeServiceFileDescriptorSupplier() {}
  }

  private static final class FacadeServiceMethodDescriptorSupplier
      extends FacadeServiceBaseDescriptorSupplier
      implements io.grpc.protobuf.ProtoMethodDescriptorSupplier {
    private final String methodName;

    FacadeServiceMethodDescriptorSupplier(String methodName) {
      this.methodName = methodName;
    }

    @java.lang.Override
    public com.google.protobuf.Descriptors.MethodDescriptor getMethodDescriptor() {
      return getServiceDescriptor().findMethodByName(methodName);
    }
  }

  private static volatile io.grpc.ServiceDescriptor serviceDescriptor;

  public static io.grpc.ServiceDescriptor getServiceDescriptor() {
    io.grpc.ServiceDescriptor result = serviceDescriptor;
    if (result == null) {
      synchronized (FacadeServiceGrpc.class) {
        result = serviceDescriptor;
        if (result == null) {
          serviceDescriptor = result = io.grpc.ServiceDescriptor.newBuilder(SERVICE_NAME)
              .setSchemaDescriptor(new FacadeServiceFileDescriptorSupplier())
              .addMethod(getControlMethod())
              .build();
        }
      }
    }
    return result;
  }
}
