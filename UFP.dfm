object FP: TFP
  Left = 564
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Juegos Reunidos'
  ClientHeight = 45
  ClientWidth = 430
  Color = clHighlightText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PrintScale = poNone
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnMouseUp = FormMouseUp
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 392
    Top = 8
    object Juego: TMenuItem
      Caption = '&Juego'
      object Otelo: TMenuItem
        Caption = '&Otelo'
        OnClick = OteloClick
      end
      object Conecta4: TMenuItem
        Caption = '&Conecta4'
        OnClick = Conecta4Click
      end
      object TresEnRaya: TMenuItem
        Caption = '&Tres en raya'
        OnClick = TresEnRayaClick
      end
    end
    object Jugador1: TMenuItem
      Caption = 'J&ugador'
      object Aleatorio: TMenuItem
        Caption = '&Aleatorio'
        OnClick = AleatorioClick
      end
      object Concienzudo: TMenuItem
        Caption = '&Concienzudo'
        object Bajo: TMenuItem
          Caption = '&Tozudo'
          OnClick = BajoClick
        end
        object Medio: TMenuItem
          Caption = '&Medio'
          OnClick = MedioClick
        end
        object Alto: TMenuItem
          Caption = '&Alto'
          OnClick = AltoClick
        end
      end
      object OtroUsuario: TMenuItem
        Caption = 'Otro usuario'
        OnClick = OtroUsuarioClick
      end
    end
    object Partida: TMenuItem
      Caption = '&Partida'
      object Inicia: TMenuItem
        Caption = '&Inicia'
        object Usuario: TMenuItem
          Caption = '&Usuario'
          OnClick = UsuarioClick
        end
        object Ordenador: TMenuItem
          Caption = '&Ordenador/Usuario2'
          OnClick = OrdenadorClick
        end
      end
      object Deshacer: TMenuItem
        Caption = '&Deshacer'
        OnClick = DeshacerClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Guardar: TMenuItem
        Caption = '&Guardar'
        OnClick = GuardarClick
      end
      object Cargar: TMenuItem
        Caption = '&Cargar'
        OnClick = CargarClick
      end
    end
    object OtraVentana: TMenuItem
      Caption = '&Otra Ventana'
      OnClick = OtraVentanaClick
    end
    object About: TMenuItem
      Caption = '&About'
      OnClick = AboutClick
    end
    object Salir: TMenuItem
      Caption = '&Salir'
      OnClick = SalirClick
    end
  end
  object SaveDialog: TSaveDialog
    Left = 360
    Top = 8
  end
  object OpenDialog: TOpenDialog
    Left = 328
    Top = 8
  end
end
