// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/attach_channels.proto

package com.fleetmgr.interfaces;

public final class AttachChannels {
  private AttachChannels() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_com_fleetmgr_interfaces_AttachChannelsRequest_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_com_fleetmgr_interfaces_AttachChannelsRequest_fieldAccessorTable;
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_com_fleetmgr_interfaces_ChannelsResponse_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\034common/attach_channels.proto\022\027com.flee" +
      "tmgr.interfaces\032\024common/channel.proto\"K\n" +
      "\025AttachChannelsRequest\0222\n\010channels\030\001 \003(\013" +
      "2 .com.fleetmgr.interfaces.Channel\",\n\020Ch" +
      "annelsResponse\022\030\n\020attachedChannels\030\001 \003(\004" +
      "B\002P\001b\006proto3"
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
          com.fleetmgr.interfaces.ChannelOuterClass.getDescriptor(),
        }, assigner);
    internal_static_com_fleetmgr_interfaces_AttachChannelsRequest_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_com_fleetmgr_interfaces_AttachChannelsRequest_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_com_fleetmgr_interfaces_AttachChannelsRequest_descriptor,
        new java.lang.String[] { "Channels", });
    internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor =
      getDescriptor().getMessageTypes().get(1);
    internal_static_com_fleetmgr_interfaces_ChannelsResponse_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor,
        new java.lang.String[] { "AttachedChannels", });
    com.fleetmgr.interfaces.ChannelOuterClass.getDescriptor();
  }

  // @@protoc_insertion_point(outer_class_scope)
}
