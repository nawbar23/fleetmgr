// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: facade/control/heartbeat.proto

package com.fleetmgr.interfaces.facade.control;

public final class Heartbeat {
  private Heartbeat() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatRequest_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatRequest_fieldAccessorTable;
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatResponse_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatResponse_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\036facade/control/heartbeat.proto\022&com.fl" +
      "eetmgr.interfaces.facade.control\032\025common" +
      "/location.proto\"\037\n\020HeartbeatRequest\022\013\n\003k" +
      "ey\030\001 \001(\003\"U\n\021HeartbeatResponse\022\013\n\003key\030\001 \001" +
      "(\003\0223\n\010location\030\002 \001(\0132!.com.fleetmgr.inte" +
      "rfaces.LocationB\002P\001b\006proto3"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
          com.fleetmgr.interfaces.LocationOuterClass.getDescriptor(),
        }, assigner);
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatRequest_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatRequest_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatRequest_descriptor,
        new java.lang.String[] { "Key", });
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatResponse_descriptor =
      getDescriptor().getMessageTypes().get(1);
    internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatResponse_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_com_fleetmgr_interfaces_facade_control_HeartbeatResponse_descriptor,
        new java.lang.String[] { "Key", "Location", });
    com.fleetmgr.interfaces.LocationOuterClass.getDescriptor();
  }

  // @@protoc_insertion_point(outer_class_scope)
}
