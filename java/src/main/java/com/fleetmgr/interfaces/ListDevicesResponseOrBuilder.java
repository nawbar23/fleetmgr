// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: core/list_devices.proto

package com.fleetmgr.interfaces;

public interface ListDevicesResponseOrBuilder extends
    // @@protoc_insertion_point(interface_extends:com.fleetmgr.interfaces.ListDevicesResponse)
    com.google.protobuf.MessageOrBuilder {

  /**
   * <code>repeated .com.fleetmgr.interfaces.Device devices = 1;</code>
   */
  java.util.List<com.fleetmgr.interfaces.Device> 
      getDevicesList();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Device devices = 1;</code>
   */
  com.fleetmgr.interfaces.Device getDevices(int index);
  /**
   * <code>repeated .com.fleetmgr.interfaces.Device devices = 1;</code>
   */
  int getDevicesCount();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Device devices = 1;</code>
   */
  java.util.List<? extends com.fleetmgr.interfaces.DeviceOrBuilder> 
      getDevicesOrBuilderList();
  /**
   * <code>repeated .com.fleetmgr.interfaces.Device devices = 1;</code>
   */
  com.fleetmgr.interfaces.DeviceOrBuilder getDevicesOrBuilder(
      int index);
}
