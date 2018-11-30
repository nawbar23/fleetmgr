// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/handover_data.proto

package com.fleetmgr.interfaces;

/**
 * Protobuf type {@code com.fleetmgr.interfaces.HandoverData}
 */
public  final class HandoverData extends
    com.google.protobuf.GeneratedMessageV3 implements
    // @@protoc_insertion_point(message_implements:com.fleetmgr.interfaces.HandoverData)
    HandoverDataOrBuilder {
private static final long serialVersionUID = 0L;
  // Use HandoverData.newBuilder() to construct.
  private HandoverData(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
    super(builder);
  }
  private HandoverData() {
    handoverData_ = "";
  }

  @java.lang.Override
  public final com.google.protobuf.UnknownFieldSet
  getUnknownFields() {
    return this.unknownFields;
  }
  private HandoverData(
      com.google.protobuf.CodedInputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    this();
    if (extensionRegistry == null) {
      throw new java.lang.NullPointerException();
    }
    int mutable_bitField0_ = 0;
    com.google.protobuf.UnknownFieldSet.Builder unknownFields =
        com.google.protobuf.UnknownFieldSet.newBuilder();
    try {
      boolean done = false;
      while (!done) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            done = true;
            break;
          default: {
            if (!parseUnknownFieldProto3(
                input, unknownFields, extensionRegistry, tag)) {
              done = true;
            }
            break;
          }
          case 10: {
            java.lang.String s = input.readStringRequireUtf8();

            handoverData_ = s;
            break;
          }
        }
      }
    } catch (com.google.protobuf.InvalidProtocolBufferException e) {
      throw e.setUnfinishedMessage(this);
    } catch (java.io.IOException e) {
      throw new com.google.protobuf.InvalidProtocolBufferException(
          e).setUnfinishedMessage(this);
    } finally {
      this.unknownFields = unknownFields.build();
      makeExtensionsImmutable();
    }
  }
  public static final com.google.protobuf.Descriptors.Descriptor
      getDescriptor() {
    return com.fleetmgr.interfaces.HandoverDataOuterClass.internal_static_com_fleetmgr_interfaces_HandoverData_descriptor;
  }

  protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internalGetFieldAccessorTable() {
    return com.fleetmgr.interfaces.HandoverDataOuterClass.internal_static_com_fleetmgr_interfaces_HandoverData_fieldAccessorTable
        .ensureFieldAccessorsInitialized(
            com.fleetmgr.interfaces.HandoverData.class, com.fleetmgr.interfaces.HandoverData.Builder.class);
  }

  public static final int HANDOVERDATA_FIELD_NUMBER = 1;
  private volatile java.lang.Object handoverData_;
  /**
   * <code>string handoverData = 1;</code>
   */
  public java.lang.String getHandoverData() {
    java.lang.Object ref = handoverData_;
    if (ref instanceof java.lang.String) {
      return (java.lang.String) ref;
    } else {
      com.google.protobuf.ByteString bs = 
          (com.google.protobuf.ByteString) ref;
      java.lang.String s = bs.toStringUtf8();
      handoverData_ = s;
      return s;
    }
  }
  /**
   * <code>string handoverData = 1;</code>
   */
  public com.google.protobuf.ByteString
      getHandoverDataBytes() {
    java.lang.Object ref = handoverData_;
    if (ref instanceof java.lang.String) {
      com.google.protobuf.ByteString b = 
          com.google.protobuf.ByteString.copyFromUtf8(
              (java.lang.String) ref);
      handoverData_ = b;
      return b;
    } else {
      return (com.google.protobuf.ByteString) ref;
    }
  }

  private byte memoizedIsInitialized = -1;
  public final boolean isInitialized() {
    byte isInitialized = memoizedIsInitialized;
    if (isInitialized == 1) return true;
    if (isInitialized == 0) return false;

    memoizedIsInitialized = 1;
    return true;
  }

  public void writeTo(com.google.protobuf.CodedOutputStream output)
                      throws java.io.IOException {
    if (!getHandoverDataBytes().isEmpty()) {
      com.google.protobuf.GeneratedMessageV3.writeString(output, 1, handoverData_);
    }
    unknownFields.writeTo(output);
  }

  public int getSerializedSize() {
    int size = memoizedSize;
    if (size != -1) return size;

    size = 0;
    if (!getHandoverDataBytes().isEmpty()) {
      size += com.google.protobuf.GeneratedMessageV3.computeStringSize(1, handoverData_);
    }
    size += unknownFields.getSerializedSize();
    memoizedSize = size;
    return size;
  }

  @java.lang.Override
  public boolean equals(final java.lang.Object obj) {
    if (obj == this) {
     return true;
    }
    if (!(obj instanceof com.fleetmgr.interfaces.HandoverData)) {
      return super.equals(obj);
    }
    com.fleetmgr.interfaces.HandoverData other = (com.fleetmgr.interfaces.HandoverData) obj;

    boolean result = true;
    result = result && getHandoverData()
        .equals(other.getHandoverData());
    result = result && unknownFields.equals(other.unknownFields);
    return result;
  }

  @java.lang.Override
  public int hashCode() {
    if (memoizedHashCode != 0) {
      return memoizedHashCode;
    }
    int hash = 41;
    hash = (19 * hash) + getDescriptor().hashCode();
    hash = (37 * hash) + HANDOVERDATA_FIELD_NUMBER;
    hash = (53 * hash) + getHandoverData().hashCode();
    hash = (29 * hash) + unknownFields.hashCode();
    memoizedHashCode = hash;
    return hash;
  }

  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      java.nio.ByteBuffer data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      java.nio.ByteBuffer data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      com.google.protobuf.ByteString data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      com.google.protobuf.ByteString data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(byte[] data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      byte[] data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.HandoverData parseDelimitedFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.HandoverData parseDelimitedFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      com.google.protobuf.CodedInputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.HandoverData parseFrom(
      com.google.protobuf.CodedInputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input, extensionRegistry);
  }

  public Builder newBuilderForType() { return newBuilder(); }
  public static Builder newBuilder() {
    return DEFAULT_INSTANCE.toBuilder();
  }
  public static Builder newBuilder(com.fleetmgr.interfaces.HandoverData prototype) {
    return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
  }
  public Builder toBuilder() {
    return this == DEFAULT_INSTANCE
        ? new Builder() : new Builder().mergeFrom(this);
  }

  @java.lang.Override
  protected Builder newBuilderForType(
      com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
    Builder builder = new Builder(parent);
    return builder;
  }
  /**
   * Protobuf type {@code com.fleetmgr.interfaces.HandoverData}
   */
  public static final class Builder extends
      com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
      // @@protoc_insertion_point(builder_implements:com.fleetmgr.interfaces.HandoverData)
      com.fleetmgr.interfaces.HandoverDataOrBuilder {
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return com.fleetmgr.interfaces.HandoverDataOuterClass.internal_static_com_fleetmgr_interfaces_HandoverData_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.fleetmgr.interfaces.HandoverDataOuterClass.internal_static_com_fleetmgr_interfaces_HandoverData_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.fleetmgr.interfaces.HandoverData.class, com.fleetmgr.interfaces.HandoverData.Builder.class);
    }

    // Construct using com.fleetmgr.interfaces.HandoverData.newBuilder()
    private Builder() {
      maybeForceBuilderInitialization();
    }

    private Builder(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      super(parent);
      maybeForceBuilderInitialization();
    }
    private void maybeForceBuilderInitialization() {
      if (com.google.protobuf.GeneratedMessageV3
              .alwaysUseFieldBuilders) {
      }
    }
    public Builder clear() {
      super.clear();
      handoverData_ = "";

      return this;
    }

    public com.google.protobuf.Descriptors.Descriptor
        getDescriptorForType() {
      return com.fleetmgr.interfaces.HandoverDataOuterClass.internal_static_com_fleetmgr_interfaces_HandoverData_descriptor;
    }

    public com.fleetmgr.interfaces.HandoverData getDefaultInstanceForType() {
      return com.fleetmgr.interfaces.HandoverData.getDefaultInstance();
    }

    public com.fleetmgr.interfaces.HandoverData build() {
      com.fleetmgr.interfaces.HandoverData result = buildPartial();
      if (!result.isInitialized()) {
        throw newUninitializedMessageException(result);
      }
      return result;
    }

    public com.fleetmgr.interfaces.HandoverData buildPartial() {
      com.fleetmgr.interfaces.HandoverData result = new com.fleetmgr.interfaces.HandoverData(this);
      result.handoverData_ = handoverData_;
      onBuilt();
      return result;
    }

    public Builder clone() {
      return (Builder) super.clone();
    }
    public Builder setField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        java.lang.Object value) {
      return (Builder) super.setField(field, value);
    }
    public Builder clearField(
        com.google.protobuf.Descriptors.FieldDescriptor field) {
      return (Builder) super.clearField(field);
    }
    public Builder clearOneof(
        com.google.protobuf.Descriptors.OneofDescriptor oneof) {
      return (Builder) super.clearOneof(oneof);
    }
    public Builder setRepeatedField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        int index, java.lang.Object value) {
      return (Builder) super.setRepeatedField(field, index, value);
    }
    public Builder addRepeatedField(
        com.google.protobuf.Descriptors.FieldDescriptor field,
        java.lang.Object value) {
      return (Builder) super.addRepeatedField(field, value);
    }
    public Builder mergeFrom(com.google.protobuf.Message other) {
      if (other instanceof com.fleetmgr.interfaces.HandoverData) {
        return mergeFrom((com.fleetmgr.interfaces.HandoverData)other);
      } else {
        super.mergeFrom(other);
        return this;
      }
    }

    public Builder mergeFrom(com.fleetmgr.interfaces.HandoverData other) {
      if (other == com.fleetmgr.interfaces.HandoverData.getDefaultInstance()) return this;
      if (!other.getHandoverData().isEmpty()) {
        handoverData_ = other.handoverData_;
        onChanged();
      }
      this.mergeUnknownFields(other.unknownFields);
      onChanged();
      return this;
    }

    public final boolean isInitialized() {
      return true;
    }

    public Builder mergeFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      com.fleetmgr.interfaces.HandoverData parsedMessage = null;
      try {
        parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        parsedMessage = (com.fleetmgr.interfaces.HandoverData) e.getUnfinishedMessage();
        throw e.unwrapIOException();
      } finally {
        if (parsedMessage != null) {
          mergeFrom(parsedMessage);
        }
      }
      return this;
    }

    private java.lang.Object handoverData_ = "";
    /**
     * <code>string handoverData = 1;</code>
     */
    public java.lang.String getHandoverData() {
      java.lang.Object ref = handoverData_;
      if (!(ref instanceof java.lang.String)) {
        com.google.protobuf.ByteString bs =
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        handoverData_ = s;
        return s;
      } else {
        return (java.lang.String) ref;
      }
    }
    /**
     * <code>string handoverData = 1;</code>
     */
    public com.google.protobuf.ByteString
        getHandoverDataBytes() {
      java.lang.Object ref = handoverData_;
      if (ref instanceof String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        handoverData_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }
    /**
     * <code>string handoverData = 1;</code>
     */
    public Builder setHandoverData(
        java.lang.String value) {
      if (value == null) {
    throw new NullPointerException();
  }
  
      handoverData_ = value;
      onChanged();
      return this;
    }
    /**
     * <code>string handoverData = 1;</code>
     */
    public Builder clearHandoverData() {
      
      handoverData_ = getDefaultInstance().getHandoverData();
      onChanged();
      return this;
    }
    /**
     * <code>string handoverData = 1;</code>
     */
    public Builder setHandoverDataBytes(
        com.google.protobuf.ByteString value) {
      if (value == null) {
    throw new NullPointerException();
  }
  checkByteStringIsUtf8(value);
      
      handoverData_ = value;
      onChanged();
      return this;
    }
    public final Builder setUnknownFields(
        final com.google.protobuf.UnknownFieldSet unknownFields) {
      return super.setUnknownFieldsProto3(unknownFields);
    }

    public final Builder mergeUnknownFields(
        final com.google.protobuf.UnknownFieldSet unknownFields) {
      return super.mergeUnknownFields(unknownFields);
    }


    // @@protoc_insertion_point(builder_scope:com.fleetmgr.interfaces.HandoverData)
  }

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.HandoverData)
  private static final com.fleetmgr.interfaces.HandoverData DEFAULT_INSTANCE;
  static {
    DEFAULT_INSTANCE = new com.fleetmgr.interfaces.HandoverData();
  }

  public static com.fleetmgr.interfaces.HandoverData getDefaultInstance() {
    return DEFAULT_INSTANCE;
  }

  private static final com.google.protobuf.Parser<HandoverData>
      PARSER = new com.google.protobuf.AbstractParser<HandoverData>() {
    public HandoverData parsePartialFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return new HandoverData(input, extensionRegistry);
    }
  };

  public static com.google.protobuf.Parser<HandoverData> parser() {
    return PARSER;
  }

  @java.lang.Override
  public com.google.protobuf.Parser<HandoverData> getParserForType() {
    return PARSER;
  }

  public com.fleetmgr.interfaces.HandoverData getDefaultInstanceForType() {
    return DEFAULT_INSTANCE;
  }

}

