/*
 * Copyright (c) 2000, 2025, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * https://oss.oracle.com/licenses/upl.
 */
#ifndef COH_SSL_SOCKET_PROVIDER_FACTORY_HPP
#define COH_SSL_SOCKET_PROVIDER_FACTORY_HPP

#include "coherence/lang.ns"
#include "coherence/net/SslSocketProvider.hpp"
#include "coherence/net/SocketProviderFactory.hpp"
#include "coherence/run/xml/XmlConfigurable.hpp"
#include "coherence/run/xml/XmlElement.hpp"

COH_OPEN_NAMESPACE2(coherence,net)

using coherence::run::xml::XmlConfigurable;
using coherence::run::xml::XmlElement;

class COH_EXPORT SslSocketProviderFactory
      : public class_spec<SslSocketProviderFactory,
        extends<Object>,
        implements<XmlConfigurable> >
    {
    friend class factory<SslSocketProviderFactory>;

    // ----- constructors ---------------------------------------------------

    protected:
        /**
         * Create a new SslSocketProviderFactory instance
         */
        SslSocketProviderFactory();

    public:
        virtual SslSocketProvider::Handle createSslSocketProvider(ClassLoader::View vLoader = NULL);

    // ----- XmlConfigurable interface---------------------------------------

    public:
        /**
        * {@inheritDoc}
        */
        virtual void setConfig(XmlElement::View xml);

        /**
        * {@inheritDoc}
        */
        virtual XmlElement::View getConfig() const;

    // ----- Object interface -----------------------------------------------

    public:
        /**
        * {@inheritDoc}
        */
        virtual TypedHandle<const String> toString() const;

    // ---- data members ----------------------------------------------------

    protected:
        /**
         * XML configuration for this SslSocketProvider.
         */
        FinalView<XmlElement> f_vXmlConfig;

    };

COH_CLOSE_NAMESPACE2

#endif // COH_SSL_SOCKET_PROVIDER_FACTORY_HPP
