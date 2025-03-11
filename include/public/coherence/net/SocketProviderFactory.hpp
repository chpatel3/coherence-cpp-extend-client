/*
 * Copyright (c) 2000, 2025, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * https://oss.oracle.com/licenses/upl.
 */
#ifndef COH_SOCKET_PROVIDER_FACTORY_HPP
#define COH_SOCKET_PROVIDER_FACTORY_HPP

#include "coherence/lang.ns"
#include "coherence/net/SslSocketProvider.hpp"

COH_OPEN_NAMESPACE2(coherence,net)

using coherence::run::xml::XmlConfigurable;
using coherence::run::xml::XmlElement;

class COH_EXPORT SocketProviderFactory
    : public interface_spec<SocketProviderFactory>
    {
    // ----- constructors ---------------------------------------------------

    public:
        /**
         * Create a new SocketProviderFactory instance
         */
        SocketProviderFactory();

    public:
        virtual SslSocketProvider::Handle createSslSocketProvider(ClassLoader::View vLoader = NULL);
    };

COH_CLOSE_NAMESPACE2

#endif // COH_SOCKET_PROVIDER_FACTORY_HPP
