// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/add_channels.proto

package com.fleetmgr.interfaces;

public interface AddChannelsResponseOrBuilder extends
    // @@protoc_insertion_point(interface_extends:com.fleetmgr.interfaces.AddChannelsResponse)
    com.google.protobuf.MessageOrBuilder {

  /**
   * <code>repeated .com.fleetmgr.interfaces.Channel channel = 1;</code>
   */
  java.util.List<com.fleetmgr.interfaces.Channel> 
      getChannelList();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Channel channel = 1;</code>
   */
  com.fleetmgr.interfaces.Channel getChannel(int index);
  /**
   * <code>repeated .com.fleetmgr.interfaces.Channel channel = 1;</code>
   */
  int getChannelCount();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Channel channel = 1;</code>
   */
  java.util.List<? extends com.fleetmgr.interfaces.ChannelOrBuilder> 
      getChannelOrBuilderList();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Channel channel = 1;</code>
   */
  com.fleetmgr.interfaces.ChannelOrBuilder getChannelOrBuilder(
      int index);
}
