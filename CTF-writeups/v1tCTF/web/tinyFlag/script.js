
(function () {
    var s = document.createElement('style');
    s.textContent = '\n/* dynamic layer: tiny sparkles */\n.dynamic-spark{position:absolute;left:0;top:0;width:6px;height:6px;background:var(--accent);opacity:0.05;transform:rotate(180deg);box-shadow: 96px 20px var(--accent), 480px 60px var(--accent), 1120px 16px var(--accent);}\n';
    document.head.appendChild(s);

    var d = document.createElement('div'); d.className = 'dynamic-spark'; d.setAttribute('aria-hidden', 'true'); document.body.appendChild(d);

    var trail = [];
    document.addEventListener('mousemove', function (e) {
        var el = document.createElement('div');
        el.style.position = 'fixed'; el.style.width = '6px'; el.style.height = '6px'; el.style.left = (e.clientX - 3) + 'px'; el.style.top = (e.clientY - 3) + 'px'; el.style.background = 'radial-gradient(circle at 30% 30%, rgba(255,255,255,0.9), rgba(255,255,255,0.0))'; el.style.opacity = '0.08'; el.style.borderRadius = '3px'; el.style.pointerEvents = 'none'; el.style.transition = 'opacity 600ms linear'; document.body.appendChild(el);
        trail.push(el);
        if (trail.length > 10) { var r = trail.shift(); r.style.opacity = '0'; setTimeout(() => r.remove(), 700); }
    });

})();
