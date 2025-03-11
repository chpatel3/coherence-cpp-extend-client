/*
 * Copyright (c) 2000, 2025, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * https://oss.oracle.com/licenses/upl.
 */
#include "coherence/lang.ns"
#include "coherence/net/SslSocketProvider.hpp"
#include "coherence/net/SslSocketProviderFactory.hpp"
#include "coherence/run/xml/XmlConfigurable.hpp"
#include "coherence/run/xml/XmlElement.hpp"

COH_OPEN_NAMESPACE2(coherence,net)

using coherence::run::xml::XmlElement;

// ----- constructors -------------------------------------------------------

SslSocketProviderFactory::SslSocketProviderFactory()
    : f_vXmlConfig(self())
    {
    }

// ----- AddressProviderFactory interface -----------------------------------

SslSocketProvider::Handle SslSocketProviderFactory::createSslSocketProvider(ClassLoader::View vLoader)
    {
    ClassLoader::View vClassLoader = vLoader;
    if (vClassLoader == NULL)
        {
        vClassLoader = SystemClassLoader::getInstance();
        }

    XmlElement::View vXmlConfig    = getConfig();
    String::View     vsElementName = vXmlConfig->getName();

    return SslSocketProvider::Handle();
    }

// ----- XmlConfigurable interface ------------------------------------------

void SslSocketProviderFactory::setConfig(XmlElement::View vXml)
    {
    initialize(f_vXmlConfig, vXml);
    }

 XmlElement::View SslSocketProviderFactory::getConfig() const
    {
    return f_vXmlConfig;
    }

// ----- Object interface ---------------------------------------------------

TypedHandle<const String> SslSocketProviderFactory::toString() const
    {
    return COH_TO_STRING("SslSocketProviderFactory{Xml=" << getConfig() << "}");
    }

COH_CLOSE_NAMESPACE2
