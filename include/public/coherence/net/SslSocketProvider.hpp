/*
 * Copyright (c) 2000, 2025, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * https://oss.oracle.com/licenses/upl.
 */
#ifndef COH_SSL_SOCKET_PROVIDER_HPP
#define COH_SSL_SOCKET_PROVIDER_HPP

#include "coherence/lang.ns"
#include "coherence/run/xml/XmlConfigurable.hpp"

COH_OPEN_NAMESPACE2(coherence,net)

using coherence::run::xml::XmlConfigurable;

class COH_EXPORT SslSocketProvider
      : public class_spec<SslSocketProvider,
               extends<Object> >
    {
    friend class factory<SslSocketProvider>;
 
    // ----- constructors ---------------------------------------------------

    protected:
        /**
         * Create a new SslSocketProvider instance
         */
        SslSocketProvider();

        /**
        * Construct an instance of ConfigurableAddressProvider based on the
        * specified XML element.
        *
        * @param vXml   the XML element that contains the configuration info
        * @param fSafe  true if the provider is skips unresolved addresses
        */
       // SslSocketProvider(XmlElement::View vXml, bool fSafe = true);

    };

COH_CLOSE_NAMESPACE2

#endif // COH_SSL_SOCKET_PROVIDER_HPP
