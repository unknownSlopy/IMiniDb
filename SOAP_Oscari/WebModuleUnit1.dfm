object WebModule1: TWebModule1
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end>
  Height = 288
  Width = 519
  PixelsPerInch = 120
  object HTTPSoapDispatcher1: THTTPSoapDispatcher
    Dispatcher = HTTPSoapCppInvoker1
    WebDispatch.PathInfo = 'soap*'
    Left = 75
    Top = 14
  end
  object HTTPSoapCppInvoker1: THTTPSoapCppInvoker
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soUTF8InHeader]
    Left = 75
    Top = 84
  end
  object WSDLHTMLPublish1: TWSDLHTMLPublish
    WebDispatch.MethodType = mtAny
    WebDispatch.PathInfo = 'wsdl*'
    TargetNamespace = 'http://tempuri.org/'
    PublishOptions = [poUTF8ContentType]
    Left = 75
    Top = 154
  end
end
