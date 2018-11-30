// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common/attach_channels.proto

package com.fleetmgr.interfaces;

/**
 * Protobuf type {@code com.fleetmgr.interfaces.ChannelsResponse}
 */
public  final class ChannelsResponse extends
    com.google.protobuf.GeneratedMessageV3 implements
    // @@protoc_insertion_point(message_implements:com.fleetmgr.interfaces.ChannelsResponse)
    ChannelsResponseOrBuilder {
private static final long serialVersionUID = 0L;
  // Use ChannelsResponse.newBuilder() to construct.
  private ChannelsResponse(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
    super(builder);
  }
  private ChannelsResponse() {
    attachedChannels_ = java.util.Collections.emptyList();
  }

  @java.lang.Override
  public final com.google.protobuf.UnknownFieldSet
  getUnknownFields() {
    return this.unknownFields;
  }
  private ChannelsResponse(
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
          case 8: {
            if (!((mutable_bitField0_ & 0x00000001) == 0x00000001)) {
              attachedChannels_ = new java.util.ArrayList<java.lang.Long>();
              mutable_bitField0_ |= 0x00000001;
            }
            attachedChannels_.add(input.readUInt64());
            break;
          }
          case 10: {
            int length = input.readRawVarint32();
            int limit = input.pushLimit(length);
            if (!((mutable_bitField0_ & 0x00000001) == 0x00000001) && input.getBytesUntilLimit() > 0) {
              attachedChannels_ = new java.util.ArrayList<java.lang.Long>();
              mutable_bitField0_ |= 0x00000001;
            }
            while (input.getBytesUntilLimit() > 0) {
              attachedChannels_.add(input.readUInt64());
            }
            input.popLimit(limit);
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
      if (((mutable_bitField0_ & 0x00000001) == 0x00000001)) {
        attachedChannels_ = java.util.Collections.unmodifiableList(attachedChannels_);
      }
      this.unknownFields = unknownFields.build();
      makeExtensionsImmutable();
    }
  }
  public static final com.google.protobuf.Descriptors.Descriptor
      getDescriptor() {
    return com.fleetmgr.interfaces.AttachChannels.internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor;
  }

  protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internalGetFieldAccessorTable() {
    return com.fleetmgr.interfaces.AttachChannels.internal_static_com_fleetmgr_interfaces_ChannelsResponse_fieldAccessorTable
        .ensureFieldAccessorsInitialized(
            com.fleetmgr.interfaces.ChannelsResponse.class, com.fleetmgr.interfaces.ChannelsResponse.Builder.class);
  }

  public static final int ATTACHEDCHANNELS_FIELD_NUMBER = 1;
  private java.util.List<java.lang.Long> attachedChannels_;
  /**
   * <code>repeated uint64 attachedChannels = 1;</code>
   */
  public java.util.List<java.lang.Long>
      getAttachedChannelsList() {
    return attachedChannels_;
  }
  /**
   * <code>repeated uint64 attachedChannels = 1;</code>
   */
  public int getAttachedChannelsCount() {
    return attachedChannels_.size();
  }
  /**
   * <code>repeated uint64 attachedChannels = 1;</code>
   */
  public long getAttachedChannels(int index) {
    return attachedChannels_.get(index);
  }
  private int attachedChannelsMemoizedSerializedSize = -1;

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
    getSerializedSize();
    if (getAttachedChannelsList().size() > 0) {
      output.writeUInt32NoTag(10);
      output.writeUInt32NoTag(attachedChannelsMemoizedSerializedSize);
    }
    for (int i = 0; i < attachedChannels_.size(); i++) {
      output.writeUInt64NoTag(attachedChannels_.get(i));
    }
    unknownFields.writeTo(output);
  }

  public int getSerializedSize() {
    int size = memoizedSize;
    if (size != -1) return size;

    size = 0;
    {
      int dataSize = 0;
      for (int i = 0; i < attachedChannels_.size(); i++) {
        dataSize += com.google.protobuf.CodedOutputStream
          .computeUInt64SizeNoTag(attachedChannels_.get(i));
      }
      size += dataSize;
      if (!getAttachedChannelsList().isEmpty()) {
        size += 1;
        size += com.google.protobuf.CodedOutputStream
            .computeInt32SizeNoTag(dataSize);
      }
      attachedChannelsMemoizedSerializedSize = dataSize;
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
    if (!(obj instanceof com.fleetmgr.interfaces.ChannelsResponse)) {
      return super.equals(obj);
    }
    com.fleetmgr.interfaces.ChannelsResponse other = (com.fleetmgr.interfaces.ChannelsResponse) obj;

    boolean result = true;
    result = result && getAttachedChannelsList()
        .equals(other.getAttachedChannelsList());
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
    if (getAttachedChannelsCount() > 0) {
      hash = (37 * hash) + ATTACHEDCHANNELS_FIELD_NUMBER;
      hash = (53 * hash) + getAttachedChannelsList().hashCode();
    }
    hash = (29 * hash) + unknownFields.hashCode();
    memoizedHashCode = hash;
    return hash;
  }

  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      java.nio.ByteBuffer data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      java.nio.ByteBuffer data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      com.google.protobuf.ByteString data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      com.google.protobuf.ByteString data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(byte[] data)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      byte[] data,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws com.google.protobuf.InvalidProtocolBufferException {
    return PARSER.parseFrom(data, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseDelimitedFrom(java.io.InputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseDelimitedFrom(
      java.io.InputStream input,
      com.google.protobuf.ExtensionRegistryLite extensionRegistry)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
      com.google.protobuf.CodedInputStream input)
      throws java.io.IOException {
    return com.google.protobuf.GeneratedMessageV3
        .parseWithIOException(PARSER, input);
  }
  public static com.fleetmgr.interfaces.ChannelsResponse parseFrom(
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
  public static Builder newBuilder(com.fleetmgr.interfaces.ChannelsResponse prototype) {
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
   * Protobuf type {@code com.fleetmgr.interfaces.ChannelsResponse}
   */
  public static final class Builder extends
      com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
      // @@protoc_insertion_point(builder_implements:com.fleetmgr.interfaces.ChannelsResponse)
      com.fleetmgr.interfaces.ChannelsResponseOrBuilder {
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return com.fleetmgr.interfaces.AttachChannels.internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.fleetmgr.interfaces.AttachChannels.internal_static_com_fleetmgr_interfaces_ChannelsResponse_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.fleetmgr.interfaces.ChannelsResponse.class, com.fleetmgr.interfaces.ChannelsResponse.Builder.class);
    }

    // Construct using com.fleetmgr.interfaces.ChannelsResponse.newBuilder()
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
      attachedChannels_ = java.util.Collections.emptyList();
      bitField0_ = (bitField0_ & ~0x00000001);
      return this;
    }

    public com.google.protobuf.Descriptors.Descriptor
        getDescriptorForType() {
      return com.fleetmgr.interfaces.AttachChannels.internal_static_com_fleetmgr_interfaces_ChannelsResponse_descriptor;
    }

    public com.fleetmgr.interfaces.ChannelsResponse getDefaultInstanceForType() {
      return com.fleetmgr.interfaces.ChannelsResponse.getDefaultInstance();
    }

    public com.fleetmgr.interfaces.ChannelsResponse build() {
      com.fleetmgr.interfaces.ChannelsResponse result = buildPartial();
      if (!result.isInitialized()) {
        throw newUninitializedMessageException(result);
      }
      return result;
    }

    public com.fleetmgr.interfaces.ChannelsResponse buildPartial() {
      com.fleetmgr.interfaces.ChannelsResponse result = new com.fleetmgr.interfaces.ChannelsResponse(this);
      int from_bitField0_ = bitField0_;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        attachedChannels_ = java.util.Collections.unmodifiableList(attachedChannels_);
        bitField0_ = (bitField0_ & ~0x00000001);
      }
      result.attachedChannels_ = attachedChannels_;
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
      if (other instanceof com.fleetmgr.interfaces.ChannelsResponse) {
        return mergeFrom((com.fleetmgr.interfaces.ChannelsResponse)other);
      } else {
        super.mergeFrom(other);
        return this;
      }
    }

    public Builder mergeFrom(com.fleetmgr.interfaces.ChannelsResponse other) {
      if (other == com.fleetmgr.interfaces.ChannelsResponse.getDefaultInstance()) return this;
      if (!other.attachedChannels_.isEmpty()) {
        if (attachedChannels_.isEmpty()) {
          attachedChannels_ = other.attachedChannels_;
          bitField0_ = (bitField0_ & ~0x00000001);
        } else {
          ensureAttachedChannelsIsMutable();
          attachedChannels_.addAll(other.attachedChannels_);
        }
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
      com.fleetmgr.interfaces.ChannelsResponse parsedMessage = null;
      try {
        parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        parsedMessage = (com.fleetmgr.interfaces.ChannelsResponse) e.getUnfinishedMessage();
        throw e.unwrapIOException();
      } finally {
        if (parsedMessage != null) {
          mergeFrom(parsedMessage);
        }
      }
      return this;
    }
    private int bitField0_;

    private java.util.List<java.lang.Long> attachedChannels_ = java.util.Collections.emptyList();
    private void ensureAttachedChannelsIsMutable() {
      if (!((bitField0_ & 0x00000001) == 0x00000001)) {
        attachedChannels_ = new java.util.ArrayList<java.lang.Long>(attachedChannels_);
        bitField0_ |= 0x00000001;
       }
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public java.util.List<java.lang.Long>
        getAttachedChannelsList() {
      return java.util.Collections.unmodifiableList(attachedChannels_);
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public int getAttachedChannelsCount() {
      return attachedChannels_.size();
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public long getAttachedChannels(int index) {
      return attachedChannels_.get(index);
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public Builder setAttachedChannels(
        int index, long value) {
      ensureAttachedChannelsIsMutable();
      attachedChannels_.set(index, value);
      onChanged();
      return this;
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public Builder addAttachedChannels(long value) {
      ensureAttachedChannelsIsMutable();
      attachedChannels_.add(value);
      onChanged();
      return this;
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public Builder addAllAttachedChannels(
        java.lang.Iterable<? extends java.lang.Long> values) {
      ensureAttachedChannelsIsMutable();
      com.google.protobuf.AbstractMessageLite.Builder.addAll(
          values, attachedChannels_);
      onChanged();
      return this;
    }
    /**
     * <code>repeated uint64 attachedChannels = 1;</code>
     */
    public Builder clearAttachedChannels() {
      attachedChannels_ = java.util.Collections.emptyList();
      bitField0_ = (bitField0_ & ~0x00000001);
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


    // @@protoc_insertion_point(builder_scope:com.fleetmgr.interfaces.ChannelsResponse)
  }

  // @@protoc_insertion_point(class_scope:com.fleetmgr.interfaces.ChannelsResponse)
  private static final com.fleetmgr.interfaces.ChannelsResponse DEFAULT_INSTANCE;
  static {
    DEFAULT_INSTANCE = new com.fleetmgr.interfaces.ChannelsResponse();
  }

  public static com.fleetmgr.interfaces.ChannelsResponse getDefaultInstance() {
    return DEFAULT_INSTANCE;
  }

  private static final com.google.protobuf.Parser<ChannelsResponse>
      PARSER = new com.google.protobuf.AbstractParser<ChannelsResponse>() {
    public ChannelsResponse parsePartialFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return new ChannelsResponse(input, extensionRegistry);
    }
  };

  public static com.google.protobuf.Parser<ChannelsResponse> parser() {
    return PARSER;
  }

  @java.lang.Override
  public com.google.protobuf.Parser<ChannelsResponse> getParserForType() {
    return PARSER;
  }

  public com.fleetmgr.interfaces.ChannelsResponse getDefaultInstanceForType() {
    return DEFAULT_INSTANCE;
  }

}

