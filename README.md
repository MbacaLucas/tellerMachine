# 🛒 Supermarket Cashier System

Un sistema de punto de venta (POS)  y modular desarrollado en **C++ moderno**. El programa simula el flujo de una caja de supermercado, gestionando inventario temporal, validación de precios y generación de boletas detalladas.

## 🚀 Características Principales

- **Gestión de Sesión:** Registro dinámico de productos mediante nombres y precios.
- **Validación de Datos:** Uso de `continue` y guardianes lógicos para prevenir errores de entrada (precios negativos).
- **Lógica de Negocio:**
  - 💎 **Premium Tracking:** Identificación automática de productos de lujo ($ > 100).
  - 🏆 **Record de Compra:** Seguimiento en tiempo real del producto más caro.
  - 🏷️ **Descuento por Volumen:** Aplicación automática de un 10% de descuento al comprar 5 o más artículos.
  - 🏛️ **Gestión Tributaria:** Cálculo de IVA (19%) sobre el subtotal neto (soy de Chile 🇨🇱.
- **Interfaz:** Cabeceras estadísticas y recibos desglosados con formato de dos decimales.

## 🛠️ Arquitectura del Código

El proyecto aplica el **Principio de Responsabilidad Única**, dividiendo la lógica en funciones especializadas:


| Función | Descripción |
| :--- | :--- |
| `isPremium` | Evalúa categorías de productos según su costo. |
| `applyDiscount` | Aplica reglas de negocio para descuentos por volumen. |
| `displayHeader` | Gestiona la interfaz de usuario durante la compra. |
| `printRecibe` | Genera el desglose final de la factura (Ticket). |

## 📦 Instalación y Uso

1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com

   g++  main.cpp -o cashier
   ./cashier
   ```

